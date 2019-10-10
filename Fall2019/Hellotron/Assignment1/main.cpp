#include "HALmod.h"

int main()
{
    string tokens [MAX_COMMAND_LINE_ARGUMENTS];
    int tokenCount;
    int commandCounter = 0;
    string shellName = "Toyshell";
    string terminator =">";
    string historyArray [SIZE_OF_HISTORY];
    int historyArrayCounter = 0;



    //char **c; 

    do
    {
        tokenCount = GetCommand(tokens, commandCounter, shellName, terminator);
        // c = ConvertToC(tokens, tokenCount);
        // CleanUpCArray(c, tokenCount);
        
    } while (ProcessCommand (tokens, tokenCount, commandCounter, shellName, terminator, historyArray, historyArrayCounter));

    return 0;
}
