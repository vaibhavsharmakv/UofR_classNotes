#include "HALmod.h"

int main()
{
    string tokens [MAX_COMMAND_LINE_ARGUMENTS];
    int tokenCount;

    do
    {
        tokenCount = GetCommand (tokens);
    } while (ProcessCommand (tokens, tokenCount));

    return 0;
}
