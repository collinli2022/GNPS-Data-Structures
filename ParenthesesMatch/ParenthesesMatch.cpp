// Collin Li
// Data Structures
// 03/15/2021
// DuckDuckGoose MiniProject 

// Preprocessor directive
#include <iostream>
#include <string>
#include <fstream>
#include<bits/stdc++.h> 
using namespace std;
class Stack {
  private:
    Stack* previous;
    Stack* next;
    string value;
  public:
    string LEFT = "([{<";
    string RIGHT = ")]}>";
    bool checkParen(string s);

    Stack(string a, Stack* b=NULL, Stack* n=NULL); // constructor

    Stack* add(string a, Stack* head); // add to top of stack

    string pop(Stack* head); // get head and remove head

    // Getters
    string getValue() { return value; }
    Stack* getNext() { return next; }
    Stack* getPrevious() { return previous; }
    
    ~Stack() { delete next; } // deconstructor that deletes pointer
};

class ParenMatch
{
  public:
    string LEFT = "([{<";
    string RIGHT = ")]}>";
  
    ~ParenMatch() {} // deconstructor that deletes pointer
};


Stack::Stack(string a, Stack* b, Stack* n) { // sets string and pointers
  value = a;
  previous = b; 
  next = n;
}

Stack* Stack::add(string a, Stack* head) {
  Stack* newHead = new Stack(a, NULL, head); // next is previous head
  head->previous = newHead;
  return newHead;
}

string Stack::pop(Stack* head) {
  if(head == NULL) {
    return NULL;
  }
  string returnStr = head->value;
  head->next->previous = NULL;
  Stack* newHead = head->next;
  head->next = NULL;
  head = nullptr;
  head = newHead;
  return returnStr;
}
Ask mrs zinn how to return both the pop output and set head to be new head

/*
Write a program called ParenthesesMatch that first prompts the user for the name of a file and then checks to see whether or not the parentheses for each line match. The txt file will contain a series of runs of the program, where each line consists of mathematical expressions involving the bracket symbols. Your program must output the trial number followed by a colon and a single space and then the result of the call to checkParen, one trial per line, in a new text file called "result.txt" that is created by your program. Your program MUST use a stack to run each trial. Standard rules apply for formatting and usability. 4 points for documentation, 4 points for user-friendliness, 24 points for the required functionality (file read, stack, file write, correct result for each trial).
*/

int main() {
  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string inputName;
  cin >> inputName;

  string line;
  ifstream fileInput(inputName);
  ofstream fileOutput;
  fileOutput.open("result.txt");
  
  int trialIndex = 0;
  if (fileInput.is_open()) { // open file
    while ( getline (fileInput, line) ) { // get lines
      string equation = line;
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}