#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

using namespace std;

//The following two lines come from HALglobals.h
const int MAX_COMMAND_LINE_ARGUMENTS = 8;
const int SLEEP_DELAY = 100000;

int GetCommand (string tokens []);
int TokenizeCommandLine (string tokens [], string commandLine);
bool CheckForCommand ();
int ProcessCommand (string tokens [], int tokenCount);
char **ConvertToC(string tokens[], int tokenCount);
bool CleanUpCArray(char **cTokens, int tokenCount);
void PrintReverse(char **cTokens, int tokenCount);

    static volatile sig_atomic_t cullProcess = 0;
