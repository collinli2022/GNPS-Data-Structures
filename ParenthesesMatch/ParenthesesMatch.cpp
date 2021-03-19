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
    Stack* next;
    string value;
  public:
    string LEFT = "([{<";
    string RIGHT = ")]}>";
    bool checkParen(string s);

    Stack(string a="", Stack* n=NULL); // constructor

    Stack* add(string a); // add to top of stack

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

Stack* Stack::add(string a) {
  if(this->value=="") {
    return new Stack(a, NULL);
  }
  Stack* newHead = new Stack(a, this); // next is previous head
  return newHead;
}

string Stack::pop() {
  string returnStr = "";
  if(this->value == "") {
    return "";
  } else if(this->next == NULL) {
    returnStr = this->value;
    this->value.clear();
    return returnStr;
  }
  returnStr = this->value;
  Stack* newHead = this->next; // new head
  this->next = newHead->next;
  this->value = newHead->value;
  return returnStr;
}

class ParenMatch {
  public:
    string LEFT = "([{<";
    string RIGHT = ")]}>";
    
    ParenMatch() {}; // default constructor
  
    bool checkParen(string input) {
      Stack* stack = new Stack();
      bool justNumbers = true;
      // Traverse the string 
      for (int i = 0; i < input.length(); i++) {

        if (LEFT.find(input[i]) != string::npos) {
          justNumbers = false;
          string temp(1, input[i]);
          stack = stack->add(temp);
        } else if (RIGHT.find(input[i]) != string::npos) {
          // stack->printMe(stack); 
          int index1 = RIGHT.find(input[i]);
          string popped = stack->pop();
          if(popped == "") {
            return false;
          }
          int index2 = LEFT.find(popped);
          // cout << "Compare: " << input[i] <<  " - " << popped << endl;
          // cout << index1 << " _ " << index2 << endl;
          
          if(index1 != index2) { return false; }
        }
      }
      
      // stack->printMe(stack);
      // cout << " -- " << (stack->pop() == "") << endl;

      if(stack->pop() != "" && !justNumbers) { // last check to make sure stack is empty - if it was just numbers then do not return false
        return false;
      }
      return true;
    }

    ~ParenMatch() {} // deconstructor that deletes pointer
};



/*
Write a program called ParenthesesMatch that first prompts the user for the name of a file and then checks to see whether or not the parentheses for each line match. The txt file will contain a series of runs of the program, where each line consists of mathematical expressions involving the bracket symbols. Your program must output the trial number followed by a colon and a single space and then the result of the call to checkParen, one trial per line, in a new text file called "result.txt" that is created by your program. Your program MUST use a stack to run each trial. Standard rules apply for formatting and usability. 4 points for documentation, 4 points for user-friendliness, 24 points for the required functionality (file read, stack, file write, correct result for each trial).
*/

int main() {
  // testing
  Stack* head = new Stack();
  head = head->add("bob");
  head = head->add("no");
  
  head->printMe(head);
  
  cout << "3" << endl;
  cout << head->pop() << endl;
  cout << "4" << endl;
  cout << head->pop() << endl;
  cout << head->pop() << endl;
  
  
  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string inputName;
  cin >> inputName;

  ParenMatch solver = ParenMatch(); 

  string line;
  ifstream fileInput(inputName);
  ofstream fileOutput;
  fileOutput.open("result.txt");
  
  int trialIndex = 0;
  if (fileInput.is_open()) { // open file
    while ( getline (fileInput, line) ) { // get lines
      string equation = line;
      bool output = solver.checkParen(equation);

      if (output) {
        fileOutput << trialIndex << ": good!" << "\n";
      } else {
        fileOutput << trialIndex << ": BAD" << "\n";
      }
      trialIndex += 1;
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}