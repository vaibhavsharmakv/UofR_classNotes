#include "HALmod.h"

int main()
{
    string tokens[MAX_COMMAND_LINE_ARGUMENTS];
    int tokenCount;
    char **c;

    do
    {
        tokenCount = GetCommand(tokens);
        c = ConvertToC(tokens, tokenCount);
        PrintReverse(c, tokenCount);
        CleanUpCArray(c, tokenCount);

    } while (ProcessCommand(tokens, tokenCount));

    //answer 1 - white space
    //answer 2 -  dynamic allocation , increase readability

    return 0;
}