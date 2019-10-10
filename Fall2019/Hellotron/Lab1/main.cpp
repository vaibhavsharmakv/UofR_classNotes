#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
  char **words;
  char tempWord[100];
  char endWord[]="330!";

  words = new char *[3]; //allocate pointers to three words
  //OR words = (char **) malloc (sizeof(char *) * 3);

  //--------------
  //get two words from the user input--use strdup to dynamically allocate space 
  cout << "Please input a word (less than 100 characters): ";
  cin >> tempWord;
  words[0]=strdup(tempWord);

  cout << "Please input a second word (less than 100 characters): ";
  cin >> tempWord;
  words[1]=strdup(tempWord);

  //--------------
  //the third one hard code copy of "330!" (endWord)
  words[2]=strdup(endWord);
  
  //--------------
  //print and clean up individual words as you go
  for (int i=0; i<3; i++)
  {
     cout << words[i] << endl;
     free(words[i]);   //remember that space was set aside by strdup 

  }
  
  //--------------
  //Clean up the array of words
  delete [] words;     // cleans up words = new char *[3];
  //OR if you used malloc: free (words);

}