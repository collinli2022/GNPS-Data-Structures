// Collin Li
// Data Structures
// 03/15/2021
// ParenthesesMatch Project 

// Preprocessor directive
#include <iostream>
#include <string>
#include <fstream>
#include<bits/stdc++.h> 
using namespace std;
class Stack {
  private:
    Stack* next;
    string value; // Stores the value
  public:
    bool checkParen(string s);

    Stack(string a="", Stack* n=NULL); // constructor

    Stack* push(string a); // add to top of stack

    string pop(); // get head and remove head

    // debugging purposes
    void printMe(Stack* head) {
      cout << "[";
      while(head != NULL)	{
        cout << head->getValue();
        head = head->getNext();
        if(head != NULL)
          cout << ", ";
      }
      cout << "]" << endl;
    }

    // Getters
    string getValue() { return value; }
    Stack* getNext() { return next; }
    
    ~Stack() { delete next; } // deconstructor that deletes pointer
};

Stack::Stack(string a, Stack* n) { // sets string and pointers
  value = a;
  next = n;
}

Stack* Stack::push(string a) {
  if(this->value=="") { // means the stack is empty
    return new Stack(a, NULL);
  }
  Stack* newHead = new Stack(a, this); // sets this node to next node and replaces head with new node
  return newHead;
}

string Stack::pop() {
  string returnStr = "";
  if(this->value == "") { // means stack is empty
    return "";
  } else if(this->next == NULL) { // means that stack has length of 1
    returnStr = this->value;
    this->value = "";
    return returnStr;
  }
  returnStr = this->value;
  Stack* newHead = this->next; // new head
  this->next = newHead->next; // set old head to new head
  this->value = newHead->value;
  newHead->value = ""; // delete next node since *this* head has taken it's spot
  newHead->next = nullptr;
  delete newHead;
  return returnStr;
}

class ParenMatch {
  public:
    string LEFT = "([{<";
    string RIGHT = ")]}>";
    
    ParenMatch() {}; // default constructor
  
    bool checkParen(string input) {
      Stack* stack = new Stack(); // Creates the stack that will be used
      bool justNumbers = true; // checks if input is just numbers/operators (no parenthesis)
      for (int i = 0; i < input.length(); i++) { // Traverse the string
        if (LEFT.find(input[i]) != string::npos) { // if char @ position is part of LEFT Parenthesis, add to stack
          justNumbers = false; // contains parenthesis
          string temp(1, input[i]); // convert char to string
          stack = stack->push(temp); // add parenthesis to stack
        } else if (RIGHT.find(input[i]) != string::npos) { // if char @ position is part of RIGHT Parenthesis
          int index1 = RIGHT.find(input[i]); // find type of parenthesis
          string popped = stack->pop(); // get last parentheses
          if(popped == "") { return false; } // stack should not be empty or else return false
          int index2 = LEFT.find(popped); // find type of parenthesis          
          if(index1 != index2) { return false; } // compare types of parenthesis and if not same then return false
        }
      }

      if(stack->pop() != "" && !justNumbers) { // last check to make sure stack is empty - if it was just numbers then do not return false
        return false;
      }
      return true;
    }

    ~ParenMatch() {} // deconstructor 
};



/*
Write a program called ParenthesesMatch that first prompts the user for the name of a file and then checks to see whether or not the parentheses for each line match. The txt file will contain a series of runs of the program, where each line consists of mathematical expressions involving the bracket symbols. Your program must output the trial number followed by a colon and a single space and then the result of the call to checkParen, one trial per line, in a new text file called "result.txt" that is created by your program. Your program MUST use a stack to run each trial. Standard rules apply for formatting and usability. 4 points for documentation, 4 points for user-friendliness, 24 points for the required functionality (file read, stack, file write, correct result for each trial).
*/

int main() {
  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string inputName;
  cin >> inputName;

  ParenMatch solver = ParenMatch(); // used to solve

  string line;
  ifstream fileInput(inputName); // Creates an input stream
  ofstream fileOutput;  
  
  int trialIndex = 0; // count trial number
  if (fileInput.is_open()) { // open file
    fileOutput.open("result.txt");
    while ( getline (fileInput, line) ) { // get lines
      string equation = line; // get equation
      bool output = solver.checkParen(equation); // see if grouping of parenthesis is correct
      // The two output options
      if (output) { fileOutput << trialIndex << ": good!" << "\n"; }
      else { fileOutput << trialIndex << ": BAD" << "\n"; }

      trialIndex += 1;
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}