#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


using namespace std;

//The following two lines come from HALglobals.h
const int MAX_COMMAND_LINE_ARGUMENTS = 8;
const int SLEEP_DELAY = 100000;
const int SIZE_OF_HISTORY = 10;



//int GetCommand (string tokens []);
int GetCommand(string tokens[], int& commandCounter, string& shellName, string& terminator);
int TokenizeCommandLine(string tokens[], string commandLine);
void sysCommand(string tokens[], int tokenCount);
bool CheckForCommand();
int ProcessCommand(string tokens[], int tokenCount, int &commandCounter, string &shellName, string &terminator,  vector<string> &history);
bool inRange(unsigned low, unsigned high, unsigned x);
void incrementcounter(int &commandCounter);
void stopShell(int &commandCounter, string &shellName, string &terminator);
void setShellName(string &shellName, string newName);
void setTerminator(string &terminator, string newTerminator);
void addingNewCommadToHistory(string tokens[], int tokenCount, vector<string> &history);
string concatinatedTokens(string tokens[], int tokenCount);
void printHistory(vector<string> &history);


static volatile sig_atomic_t cullProcess = 0;

