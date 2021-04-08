// Collin Li
// Data Structures
// 04/06/2021
// Infix Project 

// Preprocessor directive
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include<bits/stdc++.h> 
using namespace std;

class Stack {
  private:
    Stack* next;
    char value; // Stores the value
  public:
    bool checkParen(string s);

    Stack(char a='.', Stack* n=NULL); // constructor

    Stack* push(char a); // add to top of stack

    char pop(); // get head and remove head

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
    char getValue() { return value; }
    Stack* getNext() { return next; }
    
    ~Stack() { delete next; } // deconstructor that deletes pointer
};

Stack::Stack(char a, Stack* n) { // sets int and pointers
  value = a;
  next = n;
}

Stack* Stack::push(char a) {
  if(this->value=='.') { // means the stack is empty
    return new Stack(a, NULL);
  }
  Stack* newHead = new Stack(a, this); // sets this node to next node and replaces head with new node
  return newHead;
}

char Stack::pop() {
  char returnChr = '.';
  if(this->value == '.') { // means stack is empty
    return 0;
  } else if(this->next == NULL) { // means that stack has length of 1
    returnChr = this->value;
    this->value = '.';
    return returnChr;
  }
  returnChr = this->value;
  Stack* newHead = this->next; // new head
  this->next = newHead->next; // set old head to new head
  this->value = newHead->value;
  newHead->value = '.'; // delete next node since *this* head has taken it's spot
  newHead->next = nullptr;
  delete newHead;
  return returnChr;
}

class Infix {
  private:
    int rankChar(char c) {
      if(c == '^') { return 3; }
      else if(c == '*' || c == '/') { return 2; }
      else if(c == '+' || c == '-') { return 1; }
      else { return -1; }
    }
  public:
    Infix() {};

    // The main function to convert infix expression
    //to postfix expression
    string infixToPostfix(string infix) {
      string result = "";
      string s = infix;
      Stack* st = new Stack();
      st->push('N');
      for(int i = 0; i < infix.length(); i++) {
          
          if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) { result += s[i]; } // If the index char is an operand, add it to output string.
          else if(s[i] == '(') { st->push('('); } // If the scanned character is an '(', push it to the stack.
          else if(s[i] == ')') { // If the index char is an ')', pop and to output string from the stack until an '(' appears.
            while(st->getValue() != 'N' && st->getValue() != '(') {
              char c = st->pop();              
              result += c;
            }
            if(st->getValue() == '(') {
                char c = st->getValue();
                st->pop();
            }
          } else { // If an operator is at index
              while(st->getValue() != 'N' && isLower(s[i], st->getValue())) {
                  char c = st->pop();
                  result += c;
              }
              st->push(s[i]);
          }
      }
      
      // Pop all the remaining elements from the stack
      while(st->getValue() != 'N') {
          char c = st->pop();
          result += c;
      }
      return result;    
    }

    //returns true if c1 has lower or equal precedence than c2
    bool isLower(char c1, char c2){
      return rankChar(c1) <= rankChar(c2);
    }
};

int main() {
  

  Infix infix = Infix(); // used to solve

  // TESTING
  cout << "Start" << endl;
  cout << infix.infixToPostfix("3*(4*5–6+2)") << endl;

  string line;
  ifstream fileInput(inputName); // Creates an input stream
  ofstream fileOutput;  
  
  int trialIndex = 0; // count trial number
  if (fileInput.is_open()) { // open file
    fileOutput.open("result.txt");
    while ( getline (fileInput, line) ) { // get lines
      // cout << trialIndex << ": " << line << endl; // debug

      std::stringstream iss( line );
      string number;
      std::vector<string> myNumbers;
      while ( iss >> number ) {
        myNumbers.push_back( number );
      }      
      trialIndex += 1;
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}