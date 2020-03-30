/*****************************************************************
 Sockets Daemon Program

  This code was modified from Nigel Horspools, "The Berkeley
  Unix Environment".

  A daemon process is started on some host.  A socket is acquired
  for use, and it's number is displayed on the screen.  For clients
  to connect to the server, they muse use this socket number.
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/* Display error message on stderr and then exit. */
#define OOPS(msg)       {perror(msg); exit(1);}

#define MAXLINE 512

int main()
{
    struct sockaddr_in socketInformation;         /* socket information */
    struct hostent *hostInformation;              /* host information from <netdb.h>*/
    char hostname[256];                           /* host computer */
    socklen_t slen;                               /* length socket address */
    int s;                                        /* socket return value */
    int sfd;                                      /* socket descriptor returned from accept() */
    char ch[MAXLINE];                             /* character for i/o */
    int ifd;
    int num_char=MAXLINE;
  
  /*
   * Build up our network address. Notice how it is made of machine name + port.
   */

  /*Unless the variables are declared as static storage duration, they will have an arbitrary
   value upon creation. Hence, it's always a good idea to set them to a known value before using them.*/
  
  /* Clear the data structure (socketInformation) to 0's. */
    memset(&socketInformation,0,sizeof(socketInformation));

  /* Tell our socket to be of the internet family (AF_INET). */
    socketInformation.sin_family = AF_INET;

  /* Aquire the name of the current host system (the local machine). */
    gethostname(hostname,sizeof(hostname));

  /* Return misc. host information.  Store the results in the
   * hostInformation (hostent) data structure.  */
    hostInformation = gethostbyname(hostname);

  /* Copy the host address to the socket data structure. */
    memcpy(&socketInformation.sin_addr, hostInformation->h_addr, hostInformation->h_length);

  /* Convert the integer Port Number to the network-short standard
   * required for networking stuff. This accounts for byte order differences.*/
    socketInformation.sin_port = htons(0);
  /*The htons() function makes sure that numbers are stored in memory in network byte order, 
  which is with the most significant byte first. It will therefore swap the bytes making up the number 
  so that in memory the bytes will be stored in the order*/
  
  /*
   * Now that we have our data structure full of useful information,
   * open up the socket the way we want to use it.
   */
  s = socket(AF_INET, SOCK_STREAM, 0);
  if(s == -1)
    OOPS("socket");

  /* Register our address with the system. */
  if(bind(s,(struct sockaddr *)&socketInformation,sizeof(socketInformation)) != 0)
    OOPS("bind");

  /* Display the port that has been assigned to us. */
  slen = sizeof(socketInformation);
  getsockname(s,(struct sockaddr *)&socketInformation,&slen);
  printf("Socket assigned: %d\n",ntohs(socketInformation.sin_port));
  /*The ntohs() function converts the unsigned short integer netshort from network byte order to host byte order.*/

  /* Tell socket to wait for input.  Queue length is 1. */
  if(listen(s,1) != 0)
    OOPS("listen");

  /* Loop indefinately and wait for events. */
  for(;;)
  {
    /* Wait in the 'accept()' call for a client to make a connection. */
    /* NUll == Not caring about the client info here*/
    sfd = accept(s,NULL,NULL);
    if(sfd == -1)
      OOPS("accept");
      
    /* Open our file for copying to the socket. */
    ifd = open("./junk.txt", O_RDONLY);
    if(ifd == -1)
      write(sfd,"No information, dude.\n", strlen("No information, dude.\n"));
    else
    {
      /*Read from file, write to socket*/
      while((num_char=read(ifd,ch,MAXLINE))> 0)
        if (write(sfd,ch,num_char) < num_char)
           OOPS("writing");
      close(ifd);
    }
    close(sfd);
  }

  return 0;
} 