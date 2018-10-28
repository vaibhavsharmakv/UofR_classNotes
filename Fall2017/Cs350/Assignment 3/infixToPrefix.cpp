#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include <string.h>
#define MAX 20

using namespace std;

char stack[MAX];
int top = -1;

//Push Function
void push(char item){
 top++;
 stack[top]=item;
}

//Pop Function
char pop(){
 char a;
 a=stack[top];
 top--;
  return a;
}


//Function to analyze the precidence of operators
int prcd(char symbol){
 switch(symbol) {
	case '+':
	case '-':
	 return 2;
	case '*':
	case '/':
	 return 4;
	case '(':
	case ')':
	case '#': 
	 return 1;
 }
}

//Function to sort operators from other data
int isoperator(char symbol){
 switch(symbol) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	 return 1;
	default:
	 return 0;
 }
}

//Function to invert infix to prefix
void convertip(char infix[],char prefix[]){
int i,symbol,j=0;
char test[MAX]; 

infix=strrev(infix); //Used 'strrev' to reverse string
stack[++top]='#';

for(i=0;i<strlen(infix);i++){
 symbol=infix[i];
  if(isoperator(symbol)==0){
   prefix[j]=symbol;
   j++;
  }
  else{
   if(symbol==')'){
    push(symbol);
   }
   else if(symbol=='('){
    while(stack[top]!=')'){
     prefix[j]=pop();
     j++;
    }
    pop();//pop out (.
   }
   else{
    if(prcd(symbol)>prcd(stack[top])) {
    push(symbol);
   }
   else{
    while(prcd(symbol)<=prcd(stack[top])) {
     prefix[j]=pop();
     j++;
    }
    push(symbol);
   }//end of else.
  }//end of else.
 }//end of else.
}//end of for.

while(stack[top]!='#'){
 prefix[j]=pop();
 j++;
}

prefix[j]='\0';//null terminate string.
prefix=strrev(prefix);
}




int main() {
char infix[20],prefix[20];

cout << "Enter the valid infix string: " << endl;
gets(infix);
convertip(infix,prefix);
cout << "The corresponding prefix string is: " << endl;
puts(prefix);

getch();
return 0;c

}

