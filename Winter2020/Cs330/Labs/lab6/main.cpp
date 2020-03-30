

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
using namespace std;

int main()
{
    char *const argv1[] = {(char *const) "grep", (char *const) "-o", (char *const) "color", (char *const) "colorfile.txt", (char *const)NULL};
    char *const argv2[] = {(char *const) "wc", (char *const) "-w", (char *const)NULL};

    int fdes[2];

    if (pipe(fdes) == -1)
    {
        perror("Pipe error");
        exit(2);
    }

    switch (fork())
    {
    case -1: //Error
        perror("Fork error");
        exit(3);
    case 0: //Child process
        dup2(fdes[1], fileno(stdout));
        close(fdes[0]);
        close(fdes[1]);
        execvp("/bin/grep", argv1);
        exit(3);
    default: //parent process
        dup2(fdes[0], fileno(stdin));
        int fd = open("newfile.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        dup2(fd, 1);
        close(fdes[0]);
        close(fdes[1]);

        execvp("/bin/wc", argv2);
        exit(4);
    }
}

/*
	Command used for part 1 : grep -v -n color colorfile.txt > color.txt
*/
