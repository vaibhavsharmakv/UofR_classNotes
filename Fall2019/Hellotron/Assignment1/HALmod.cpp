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

char ** ConvertToC (string tokens [], int tokenCount){ 
    char ** words; 
    words = ( char **) malloc ( sizeof ( char *) * tokenCount); 
    int i; 
    for(i =0; i < tokenCount; i++){ 
    words[i]= strdup(tokens[i].c_str()); 
    } 
    return words; 
}

bool CleanUpCArray(char **cTokens, int tokenCount){
    for (int i = 0; i < tokenCount; i++)
    {
        free(cTokens[i]);
    }
    delete[] cTokens;
    return true;
}

void PrintCh(char **cTokens, int tokenCount){
    
    for (int i = 0; i < tokenCount; i++)
    {
        //result += cTokens[i];
        cout << cTokens[i] << " ";
    }
    cout << endl;
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
int ProcessCommand(string tokens[], int tokenCount, int &commandCounter, string &shellName, string &terminator, string historyArray[], int &historyArrayCounter)
{   
    bool linuxCommand = true;
    incrementcounter(commandCounter);
    addingNewCommadToHistory(tokens, tokenCount, historyArray, historyArrayCounter);
    historyArrayCounter++;

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
        printHistory(historyArray, historyArrayCounter);
        return 1;
    }
    else if (tokens[0] == "!"){
        linuxCommand = false;
        // errrr  - token count > 1

        string strCommand = tokens[1];
        int intCommand = stoi(strCommand);
        //error
        
        string commandToExecute = historyArray[intCommand];
        tokenCount = TokenizeCommandLine(tokens, commandToExecute);
        commandCounter--;
        ProcessCommand(tokens, tokenCount, commandCounter, shellName, terminator, historyArray, historyArrayCounter);
        
        return 1;

    }
    else if (tokens[0] == "NEWNAME"){
        linuxCommand = false;
        //error
       if(tokenCount == 2){
           // deletes previously defined Alias
           system("ls");
       }
       if(tokenCount == 3){
           // Defines Alias for another command
           system("ls");
       }
        return 1;
    }

    if(linuxCommand){
        string s = concatinatedTokens(tokens, tokenCount);
        const char *command = s.c_str();
        system(command);

        
        return 1;
    }
    else
    return 1;
    
    
    
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

void addingNewCommadToHistory(string tokens[],int tokenCount, string historyArray[], int &historyArrayCounter){

    if (historyArrayCounter < 10){
        //Array not full yet
        string input;
        input = concatinatedTokens(tokens, tokenCount);
        historyArray[historyArrayCounter] = input;
    }
    else{
        if(historyArrayCounter>=10){
            historyArrayCounter =10;
        }

        string input;
        input = concatinatedTokens(tokens, tokenCount);

        for(int i = 0; i < (SIZE_OF_HISTORY-1) ; i++){
            historyArray[i] = historyArray[i+1];
        }


      
        historyArray[9] = input;
    }

}

string concatinatedTokens(string tokens[], int tokenCount){
    string input;
    for (int i = 0; i < tokenCount; i++){
        input += tokens[i];
        input += " ";
    }
    return input;

}

void printHistory(string historyArray[], int historyArrayCounter){

   
    if(historyArrayCounter< 10){
        for (int i = 0; i <= historyArrayCounter; i++)
        {   
        cout <<historyArray[i] << endl;
            
        }

    }
    else{
        for (int i = 0; i < SIZE_OF_HISTORY; i++)
        {   
        cout <<"["<<i<<"]"<<historyArray[i] << endl;
            
        }
    }

    
   


}