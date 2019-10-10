/* 
Mario Andres Rendon Zapata
SID: 200370018
CS - 330
Assignment 2 - Toyshell extended

    - The purpose of this program is to create a shell that has some predefined
    commands. And to use the fork()
*/
#include "HALmod.h"

int main()
{
    string tokens[MAX_COMMAND_LINE_ARGUMENTS];
    int tokenCount;
    int commandCounter = 1;
    vector<string> history;
    map<string, string> aliases;
    string bgProcesses[MAX_NUMBER_OF_BG_PROCESS][4];

    do
    {
        tokenCount = GetCommand(tokens, commandCounter);
    } while (ProcessCommand(tokens, tokenCount, history, aliases, bgProcesses));

    return 0;
}
