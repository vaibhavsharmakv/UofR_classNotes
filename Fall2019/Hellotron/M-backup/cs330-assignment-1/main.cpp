/* 
Mario Andres Rendon Zapata
SID: 200370018
CS - 330
Assignment 1 - Toyshell

    - The purpose of this program is to create a shell that has some predefined
    commands.
*/
#include "HALmod.h"

int main()
{
    string tokens[MAX_COMMAND_LINE_ARGUMENTS];
    int tokenCount;
    int commandCounter = 1;
    vector<string> history;
    map<string, string> aliases;

    do
    {
        tokenCount = GetCommand(tokens, commandCounter);
    } while (ProcessCommand(tokens, tokenCount, history, aliases));

    return 0;
}
