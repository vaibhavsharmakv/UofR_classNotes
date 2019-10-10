#include "HALmod.h"

int GetCommand(string tokens[], int &commandCounter, string &shellName, string &terminator)
{
    string commandLine;
    bool commandEntered;
    int tokenCount;

    do 
    {
        cout << shellName << "[" << commandCounter << "]" << terminator;
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


int TokenizeCommandLine (string tokens [], string commandLine){

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
int ProcessCommand(string tokens[], int tokenCount, int &commandCounter, string &shellName, string &terminator, string historyArray[], int &historyArrayCounter, vector<string> &history)
{   

    bool linuxCommand = true;
    incrementcounter(commandCounter);
    addingNewCommadToHistory(tokens, tokenCount, history);

    // Shutdown and Restart 
    if (tokens [0] == "shutdown" || tokens [0] == "restart"){
        linuxCommand = false;
    	if (tokenCount > 1){
            cout << shellName << terminator << tokens [0] << " does not require any arguments " << endl;
                return 1;
        }
    	cout << endl;
    	cout << shellName <<" terminating ..." << endl;

        return 0;
        
    }

    // Stop 
    else if (tokens[0] == "STOP"){
        linuxCommand = false;
        cout << shellName << " is Stopping. New Session Starting now..." << endl;
        stopShell(commandCounter,shellName,terminator);
        return 1;
    }

    // Set Shell Name
    else if (tokens[0] == "SETSHELLNAME"){
        linuxCommand = false;
        //error
      
       
            setShellName(shellName, tokens[1]);
            return 1;
        
    }

    // Set Terminator
    else if (tokens[0] == "SETTERMINATOR"){
        linuxCommand = false;
        //error
        if (tokenCount > 1){
            cout << shellName << " Using Immediate Argument as the new Terminator" << endl;
            setTerminator(terminator, tokens[1]);
            return 1;
        }
        else{
            setTerminator(shellName, tokens[1]);
            return 1;
        }
    }

    // Print History
    else if (tokens[0] == "HISTORY"){
        linuxCommand = false;
        //error
        printHistory(history);
        return 1;
    }

    // Execute a Command from History
    else if (tokens[0] == "!"){

        linuxCommand = false;
        // errrr  - token count > 1

        string strCommand = tokens[1];
        int intCommand = stoi(strCommand);
        //error
        
        //string commandToExecute = historyArray[intCommand];
        if (inRange(0, SIZE_OF_HISTORY, intCommand)){

            tokenCount = TokenizeCommandLine(tokens, history[intCommand]);
            commandCounter--;
            ProcessCommand(tokens, tokenCount, commandCounter, shellName, terminator, history);
        }
        return 1;

    }
   

    else if(linuxCommand){

        sysCommand(tokens , tokenCount);
        return 1;
    }
    else
    return 1;
    
    
    
}
void sysCommand (string tokens[], int tokenCount){

    string s = concatinatedTokens(tokens, tokenCount);
    const char *command = s.c_str();
    system(command);
}
void incrementcounter(int &commandCounter){
    commandCounter++;

}

void stopShell(int &commandCounter, string &shellName, string &terminator){
    commandCounter = 0;

}

void setShellName(string &shellName, string newName){
    shellName = newName;
}

void setTerminator(string &terminator, string newTerminator){
    terminator = newTerminator;
}

string concatinatedTokens(string tokens[], int tokenCount){
    string input;
    for (int i = 0; i < tokenCount; i++){
        input += tokens[i];
        input += " ";
    }
    return input;

}
void addingNewCommadToHistory(string tokens[], int tokenCount, vector<string> &history){

    if (history.size() == SIZE_OF_HISTORY)
    {
        history.erase(history.begin());
    }
    string newCommand = concatinatedTokens(tokens,tokenCount);
    history.push_back(newCommand);
}

void printHistory(vector<string> &history){

    for (int i = 0; i < history.size(); i++)
    {
        cout << i << " " << history[i] << endl;
    }
}

// returns true if number is inside range.
bool inRange(unsigned low, unsigned high, unsigned x){
    return ((x - low) <= (high - low));
}