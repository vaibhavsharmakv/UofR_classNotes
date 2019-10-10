#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <vector>

using namespace std;

//The following two lines come from HALglobals.h
const int MAX_COMMAND_LINE_ARGUMENTS = 8;
const int SLEEP_DELAY = 100000;
const int SIZE_OF_HISTORY = 10;

//int GetCommand (string tokens []);
int GetCommand(string tokens[], int& commandCounter, string& shellName, string& terminator);
int TokenizeCommandLine(string tokens[], string commandLine);
bool CheckForCommand ();
int ProcessCommand(string tokens[], int tokenCount, int &commandCounter, string &shellName, string &terminator, string historyArray[], int &historyArrayCounter);
char **ConvertToC(string tokens[], int tokenCount);
bool CleanUpCArray(char **cTokens, int tokenCount);
void PrintCh(char **cTokens, int tokenCount);
void incrementcounter(int& commandCounter);
void stopShell(int &commandCounter, string &shellName, string &terminator);
void setShellName(string &shellName, string newName);
void setTerminator(string &terminator, string newTerminator);
void addingNewCommadToHistory(string tokens[], int tokenCount, string historyArray[], int &historyArrayCounter);
string concatinatedTokens(string tokens[], int tokenCount);
void printHistory(string historyArray[], int historyArrayCounter);
    //void PrintReverse(char **cTokens, int tokenCount);

    static volatile sig_atomic_t cullProcess = 0;
