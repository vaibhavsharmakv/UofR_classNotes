#include "HALmod.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int GetCommand (string tokens [])
{
    string commandLine;
    bool commandEntered;
    int tokenCount;

    do
    {
        cout << "HALshell> ";
        while (1)
        {
            getline (cin, commandLine);
            commandEntered = CheckForCommand ();
            if (commandEntered)
            {
                break;
            }
           
        }
    } while (commandLine.length () == 0);

    tokenCount = TokenizeCommandLine (tokens, commandLine);

    return tokenCount;
}

int TokenizeCommandLine (string tokens [], string commandLine)
{
    char *token [MAX_COMMAND_LINE_ARGUMENTS];
    char *workCommandLine = new char [commandLine.length () + 1];
    int i;
    int tokenCount;

    for (i = 0; i < MAX_COMMAND_LINE_ARGUMENTS; i ++)
    {
        tokens [i] = "";
    }
    strcpy (workCommandLine, commandLine.c_str ());
    i = 0;
    if ((token [i] = strtok (workCommandLine, " ")) != NULL)
    {
        i ++;
        while ((token [i] = strtok (NULL, " ")) != NULL)
        {
            i ++;
        }
    }
    tokenCount = i;

    for (i = 0; i < tokenCount; i ++)
    {
        tokens [i] = token [i];
    }

    delete [] workCommandLine;

    return tokenCount;
}


//Do not touch the below function
bool CheckForCommand ()
{
    if (cullProcess)
    {
        cullProcess = 0;
        cin.clear ();
        cout << "\b\b  \b\b";
        return false;
    }

    return true;
}

	
//This is a very paired down version of Dr. Hilderman's function
int ProcessCommand (string tokens [], int tokenCount)
{
    char **c;
    if (tokens [0] == "shutdown" || tokens [0] == "restart" || tokens [0] == "lo")
    {
    	if (tokenCount > 1)
    	{
       		cout << "HALshell: " << tokens [0] << " does not require any arguments" << endl;
        	return 1;
    	}
    	cout << endl;
    	cout << "HALshell: terminating ..." << endl;

        return 0;
        
    }
    
    else 
    {
        //string s = concatinatedTokens(tokens, tokenCount);
        //const char *command = s.c_str();
        //system(command);
        ////////////////////////////////////////////
        int status;
        pid_t fork_return;

        

        fork_return = fork();

        if (fork_return == 0)
        {   
            if (tokens[0] != "exit"){
            //execl("/bin/date","date",NULL);//works
            //execl("date","date",NULL);//doesn't work
            //execlp("date","date",NULL);//works
            c = ConvertToC(tokens, tokenCount);
            char *argv[] = {c[0], c[1],c[2], NULL};
            execvp(argv[0], &argv[0]);

            }
            else{
                printf("Error on Execvp\n");
            }

        }

        else if (fork_return > 0)
        {
            wait(&status);
           
        }
        else
        {
            printf("Error\n");
        }
        return 1;
    }
   

}
char ** ConvertToC (string tokens [], int tokenCount)
{
    char ** words;
    words = (char **) malloc (sizeof (char*) * tokenCount +1);

    for (int i=0; i<tokenCount; i++)
    {
        words[i]=strdup(tokens[i].c_str());
    }
   
    return words;
}

/*

A - You were asked to add a print message after the exec* call, does it print it in all cases? Why? Why not?
Solution - it does not print message after child fork because program is running under child and wont print messages under the exec
B - Who is the parent of your executable (./demo) program?
Solution - mac OS shell , in my case TCSH
C - How would you change the code so that the child and parent "appear" to run concurrently (ie. at the same time)?
Solution - we can chaged the the parent code and make it not wait so child and parent can run cocoruntely
*/

/*
Why does child print CHILD0, CHILD1, CHILD2, etc whereas parent prints PARENT0, PARENT0, PARENT0, etc? Remember mynum is a global variable.
Solution - mynum is a global variable but it still passes different copies to child and parent so they dont interfere with each other. 
*/