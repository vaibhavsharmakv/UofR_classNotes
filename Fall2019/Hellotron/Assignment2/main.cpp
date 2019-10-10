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
    vector<string> history;


    do
    {
        tokenCount = GetCommand(tokens, commandCounter, shellName, terminator);

    } while (ProcessCommand(tokens, tokenCount, commandCounter, shellName, terminator, history));

    return 0;
}
