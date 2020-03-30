#include "2socketFunctionsHilderman.h"
#include "2socketIncludeHilderman.h"

int main (int argc, char **argv)
{
    int i;
    int socket_fd;
    struct sockaddr_in server_addr;
    struct hostent *hp;

    if (argc < 2)
    {
        printf ("argc ERROR in main: Not enough arguments");
        exit (1);
    }
    else if (argc > 2)
    {
        printf ("argc ERROR in main: Too many arguments");
        exit (1);
    }

    if ((socket_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf ("socket ERROR in main");
        exit (1);
    }

    memset (&server_addr, 0, sizeof (server_addr));
    server_addr.sin_family = AF_INET;
    hp = gethostbyname (argv [1]);
    if (hp == (struct hostent *) NULL)
    {
        printf ("gethostbyname ERROR in main: %s does not exist", argv [1]);
        exit (1);
    }
    memcpy (&server_addr.sin_addr, hp -> h_addr, hp -> h_length);
    server_addr.sin_port = htons (TCP_PORTNO);

    if (connect (socket_fd, (struct sockaddr *) &server_addr, sizeof (server_addr)) < 0)
    {
        printf ("connect ERROR in main");
        exit (1);
    }

    send_message (stdin, socket_fd);

    close (socket_fd);

    return 0;
}

void send_message (FILE *fp, int socket_fd)
{
    int i;
    int n;
    char send_line [MAX_LINE_SIZE];
    char recv_line [MAX_LINE_SIZE];

    while (fgets (send_line, MAX_LINE_SIZE, fp) != (char *) NULL)
    {
        n = strlen (send_line);
        if ((i = write_n (socket_fd, send_line, n)) != n)
        {
            printf ("write_n ERROR in send_message");
	    exit (1);
        }
        n = read_line (socket_fd, recv_line, MAX_LINE_SIZE);
        if (n < 0)
        {
            printf ("read_line ERROR in send_message");
            exit (1);
        }
        fputs (recv_line, stdout);
    }
    if (ferror (fp))
    {
        printf ("message ERROR in send_message");
        exit (1);
    }

    return;
}
