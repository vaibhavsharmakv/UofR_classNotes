#include "HALmod.h"
#include <cstring>

// Read Command from shell
int GetCommand(string tokens[], int &commandCounter)
{
    string commandLine;
    int tokenCount;

    do
    {
        PrintCommandPrompt(commandCounter);
        while (1)
        {
            getline(cin, commandLine);
            tokenCount = TokenizeCommandLine(tokens, commandLine);
            if (tokenCount > 0)
            {
                commandCounter++;
                break;
            }
            break;
        }
    } while (commandLine.length() == 0);

    return tokenCount;
}

// prints the toyshell.
void PrintCommandPrompt(int commandCounter)
{
    string terminator;
    string shellName;
    // Look for files created
    ifstream shellNameFile("shellname.txt");
    ifstream terminatorFile("terminator.txt");
    if (shellNameFile.is_open())
    {
        getline(shellNameFile, shellName);
    }
    else
    {
        // if they aren't created. create output file
        shellName = "toyshell";
        WriteToFile("shellname.txt", "toyshell");
    }

    // Two separate files are created for each property

    if (terminatorFile.is_open())
    {
        getline(terminatorFile, terminator);
    }
    else
    {
        terminator = ">";
        WriteToFile("terminator.txt", ">");
    }

    // print command prompt
    cout << shellName << "[" << commandCounter << "]" << terminator << " ";
}
// Tokenizer function from DR.Hilderman
int TokenizeCommandLine(string tokens[], string commandLine)
{
    char *token[MAX_COMMAND_LINE_ARGUMENTS];
    char *workCommandLine = new char[commandLine.length() + 1];
    int i;
    int tokenCount;

    for (i = 0; i < MAX_COMMAND_LINE_ARGUMENTS; i++)
    {
        tokens[i] = "";
    }
    strcpy(workCommandLine, commandLine.c_str());
    i = 0;
    if ((token[i] = strtok(workCommandLine, " ")) != NULL)
    {
        i++;
        while ((token[i] = strtok(NULL, " ")) != NULL)
        {
            i++;
        }
    }
    tokenCount = i;

    for (i = 0; i < tokenCount; i++)
    {
        tokens[i] = token[i];
    }

    delete[] workCommandLine;

    return tokenCount;
}

// Proccess for finding which command to use
int ProcessCommand(string tokens[], int tokenCount, vector<string> &history, map<string, string> &aliases)
{
    // check if tokens[0] is a terminating command.
    auto isATerminatingCommand = find(begin(TERMINATING_COMMANDS), end(TERMINATING_COMMANDS), tokens[0]);
    if (isATerminatingCommand == end(TERMINATING_COMMANDS))
    {
        // Add command to history
        string commandString = ReconstructCommand(tokens, tokenCount);
        AddToHistory(commandString, history);

        // check if command is a predefined shell command
        auto isAShellCommand = find(begin(SHELL_COMMANDS), end(SHELL_COMMANDS), tokens[0]);
        if (isAShellCommand != end(SHELL_COMMANDS))
        {
            if (tokenCount > 1)
            {
                // SET SHELLNAME
                if (tokens[0] == SHELL_COMMANDS[0])
                {
                    WriteToFile("shellname.txt", tokens[1]);
                }
                // SET TERMINATOR
                else if (tokens[0] == SHELL_COMMANDS[1])
                {
                    WriteToFile("terminator.txt", tokens[1]);
                }
                // execute command in history (! | [n])
                else if (tokens[0] == SHELL_COMMANDS[3] && tokens[1] == PIPE_OPERATOR && !tokens[2].empty())
                {
                    if (isNumber(tokens[2]))
                    {
                        int index = stoi(tokens[2]);
                        if (inRange(0, MAX_HISTORY_COMMANDS, index))
                        {
                            tokenCount = TokenizeCommandLine(tokens, history[index]);
                            ProcessCommand(tokens, tokenCount, history, aliases);
                        }
                    }
                }
                // NEW NAME
                else if (tokens[0] == SHELL_COMMANDS[4] && !tokens[1].empty())
                {
                    if (tokens[2].empty())
                    {
                        RemoveFromAliases(tokens[1], aliases);
                    }
                    else
                    {
                        string oldName = "";
                        string newName = tokens[1];
                        for (int i = 2; i < tokenCount; ++i)
                        {
                            oldName.append(tokens[i] + " ");
                        }
                        AddToAliases(newName, oldName, aliases);
                    }
                }
                // SAVE NEW NAMES
                else if (tokens[0] == SHELL_COMMANDS[6] && !tokens[1].empty())
                {
                    string filename = tokens[1];
                    SaveAliasesToFile(filename, aliases);
                }
                // READ NEW NAMES
                else if (tokens[0] == SHELL_COMMANDS[7] && !tokens[1].empty())
                {
                    string filename = tokens[1];
                    ReadNewNames(filename, aliases);
                }
            }
            // single token commands
            else
            {
                // HISTORY
                if (tokens[0] == SHELL_COMMANDS[2])
                {
                    PrintHistory(history);
                }
                // NEW NAMES
                else if (tokens[0] == SHELL_COMMANDS[5])
                {
                    PrintAliases(aliases);
                }
            }
            return 1;
        }
        // alias commands
        else if (CheckIfCommandInAliases(tokens[0], aliases))
        {
            // replace alias command;
            string oldName = ReconstructOldName(tokens, tokenCount, aliases);
            tokenCount = TokenizeCommandLine(tokens, oldName);
            ProcessCommand(tokens, tokenCount, history, aliases);
            return 1;
        }
        // OS/linux command
        else
        {
            string command = ReconstructCommand(tokens, tokenCount);
            OsCommand(command);
            return 1;
        }
    }
    else
    {
        cout << endl;
        cout << "toyshell terminating ..." << endl;
        return 0;
    }
}
// Adds all commands to the history data structure
void AddToHistory(string commandToAdd, vector<string> &history)
{
    if (history.size() == MAX_HISTORY_COMMANDS)
    {
        history.erase(history.begin());
    }
    history.push_back(commandToAdd);
}
// Prints the commands in the history data structure
void PrintHistory(vector<string> &history)
{
    for (int i = 0; i < history.size(); i++)
    {
        cout << i << " " << history[i] << endl;
    }
}
// writes to a file the value of the input argument
void WriteToFile(string filename, string input)
{
    ofstream newfile;
    newfile.open(filename, ios::out | ios::trunc);
    newfile << input.append("\n");
    newfile.close();
}
// concatenates the tokens to a single string
string ReconstructCommand(string tokens[], int tokenCount)
{
    string command = "";
    for (int i = 0; i < tokenCount; i++)
    {
        command.append(tokens[i] + " ");
    }
    return command;
}
// returns true if the character in the string is a number; else falsE
bool isNumber(string tokenString)
{
    for (int i = 0; i < tokenString.length(); i++)
        if (isdigit(tokenString[i]) == false)
            return false;

    return true;
}
// returns true if number is inside range.
bool inRange(unsigned low, unsigned high, unsigned x)
{
    return ((x - low) <= (high - low));
}
// adds new alias to aliases data structure
void AddToAliases(string newName, string oldName, map<string, string> &aliases)
{
    // checks that the size of the aliases data structure stays at a max of 10 elemnts
    if (aliases.size() <= MAX_ALIASES)
    {
        pair<map<string, string>::iterator, bool> ret;
        ret = aliases.insert(pair<string, string>(newName, oldName));
        if (ret.second == false)
        {
            aliases.erase(newName);
            aliases.insert(pair<string, string>(newName, oldName));
        }
    }
    else
    {
        cout << "Max Number of aliases reached" << endl;
    }
}
// remove alias from aliases data structure
void RemoveFromAliases(string aliasToRemove, map<string, string> &aliases)
{
    map<string, string>::iterator it;
    it = aliases.find(aliasToRemove);
    if (it != aliases.end())
    {
        aliases.erase(aliasToRemove);
    }
}
// print all elements in the aliases data structure
void PrintAliases(map<string, string> &aliases)
{
    map<string, string>::iterator it;
    for (it = aliases.begin(); it != aliases.end(); ++it)
    {
        cout << it->first << " => " << it->second << "\n";
    }
}
// save all aliases from data structure to a file
void SaveAliasesToFile(string filename, map<string, string> &aliases)
{
    ofstream newfile;
    newfile.open(filename, ios::out | ios::trunc);
    map<string, string>::iterator it;
    string delimiter = ":";
    for (it = aliases.begin(); it != aliases.end(); ++it)
    {
        newfile << it->first << delimiter << it->second << "\n";
    }
    newfile.close();
}
// reads all aliases from a file to aliases data structure
void ReadNewNames(string filename, map<string, string> &aliases)
{
    ifstream file;
    string alias;
    string tokens[MAX_COMMAND_LINE_ARGUMENTS];
    file.open(filename);
    if (file.is_open())
    {
        while (getline(file, alias))
        {
            ParseAliasFile(tokens, alias);
            pair<map<string, string>::iterator, bool> ret;
            ret = aliases.insert(pair<string, string>(tokens[0], tokens[1]));
        }
    }
}

void ParseAliasFile(string tokens[], string alias)
{
    string delimiter = ":";
    string key = alias.substr(0, alias.find(delimiter));
    string value = alias.substr(alias.find(delimiter) + 1, alias.length());
    tokens[0] = key;
    tokens[1] = value;
}
// checks if command entered is inside aliases data structure.
bool CheckIfCommandInAliases(string alias, map<string, string> &aliases)
{
    map<string, string>::iterator it;
    it = aliases.find(alias);
    if (it != aliases.end())
    {
        return true;
    }
    return false;
}
// passes command entered to the operating system shell
void OsCommand(string command)
{
    const char *c = command.c_str();
    system(c);
}
// Reconstructs the old command from the alias.
string ReconstructOldName(string tokens[], int tokenCount, map<string, string> &aliases)
{
    string oldName = "";
    map<string, string>::iterator aliasesIterator;
    for (int i = 0; i < tokenCount; i++)
    {
        if (i % 2 == 0)
        {
            //even
            // search for alias in aliases data structure
            aliasesIterator = aliases.find(tokens[i]);
            if (aliasesIterator != aliases.end())
            {
                // if found then add value of the alias to the oldName
                oldName = oldName.append(aliasesIterator->second + " ");
            }
            else
            {
                // if token is not an alias then is a non-alias command
                oldName = oldName.append(tokens[i] + " ");
            }
        }
        else
        {
            // Odd positions will have | or a non-alias command.
            oldName = oldName.append(tokens[i] + " ");
        }
    }
    return oldName;
}