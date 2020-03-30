/*****************************************************************
  Sockets Client Program 

  This code is a modified version taken from Nigel Horspool's "The Berkeley
  Unix Environment".

  This client connects to a specified server (host) and receives
  information from it.
*****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/* Display error message on stderr and then exit. */
#define OOPS(msg)       {perror(msg); exit(1);}

#define MAXLINE 512

int main(int argc, char *argv[])
{
  struct sockaddr_in bba; /* socket information */
  struct hostent *hp;     /* host information */
  int slen;               /* host computer */
  int s;                  /* length socket address */
  int rfd;
  char ch[MAXLINE];       /* character for i/o */
  int num_char=MAXLINE;   /* number of characters */
  int port;               /* port to connect to */

  char portnum[20];
  char hostname[20];
  printf("\n hostname:");
  scanf("%s", hostname);

  printf("\n port number:");
  scanf("%s", portnum);

  /* Clear the data structure (saddr) to 0's. */
  memset(&bba,0,sizeof(bba));

  /* Tell our socket to be of the internet family (AF_INET). (in this case, Internet Protocol v4 addresses)*/
  bba.sin_family = AF_INET;
  /* The Linux kernel supports 29 other address families such as UNIX (AF_UNIX) 
  sockets and IPX (AF_IPX), and also communications with IRDA and Bluetooth (AF_IRDA and AF_BLUETOOTH, 
  but it is doubtful you'll use these at such a low level).*/

  /* Acquire the ip address of the server */
  hp=gethostbyname(hostname);

  /* Acquire the port #. */
  port=atoi(portnum);

  /* Copy the server's address to the socket address data structure. */
  memcpy(&bba.sin_addr, hp->h_addr, hp->h_length);

  /* Convert the integer Port Number to the network-short standard
   * required for networking stuff. This accounts for byte order differences.*/
  bba.sin_port=htons(port);
  /*The htons() function makes sure that numbers are stored in memory in network byte order, 
  which is with the most significant byte first. It will therefore swap the bytes making up the number 
  so that in memory the bytes will be stored in the order*/
  
  /* Now that we have our data structure full of useful information,
   * open up the socket the way we want to use it.
   */
  s = socket(AF_INET, SOCK_STREAM, 0);
  if(s == -1)
    OOPS("socket");
  if(connect(s,(struct sockaddr *)&bba,sizeof(bba)) != 0)
    OOPS("connect");

  /* read from the socket, write to the screen */
  while( (num_char=read(s,ch,MAXLINE)) > 0 )
    if ( write(1,ch,num_char) < num_char)
      OOPS("writing");
    close(s);

  return 0;
}