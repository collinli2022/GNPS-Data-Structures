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
    int value; // Stores the value
  public:
    bool checkParen(string s);

    Stack(int a=INT_MAX, Stack* n=NULL); // constructor

    Stack* push(int a); // add to top of stack

    int pop(); // get head and remove head

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
    int getValue() { return value; }
    Stack* getNext() { return next; }
    
    ~Stack() { delete next; } // deconstructor that deletes pointer
};

Stack::Stack(int a, Stack* n) { // sets int and pointers
  value = a;
  next = n;
}

Stack* Stack::push(int a) {
  if(this->value==INT_MAX) { // means the stack is empty
    return new Stack(a, NULL);
  }
  Stack* newHead = new Stack(a, this); // sets this node to next node and replaces head with new node
  return newHead;
}

int Stack::pop() {
  int returnStr = INT_MAX;
  if(this->value == INT_MAX) { // means stack is empty
    return 0;
  } else if(this->next == NULL) { // means that stack has length of 1
    returnStr = this->value;
    this->value = INT_MAX;
    return returnStr;
  }
  returnStr = this->value;
  Stack* newHead = this->next; // new head
  this->next = newHead->next; // set old head to new head
  this->value = newHead->value;
  newHead->value = INT_MAX; // delete next node since *this* head has taken it's spot
  newHead->next = nullptr;
  delete newHead;
  return returnStr;
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
      Stack* st = new Stack();
      st = st->push('N');
      vector<string> s;
      stringstream iss(infix);
      string temp;
      while ( iss >> temp ) { s.push_back(temp); }
      for(int i=0; i < s.size(); i++) {
        /* // Debug Purposes
        cout << "index: " << s[i] << endl;
        st->printMe(st);
        cout << endl << endl;
        */
        if(s[i] == " ") {} // Do nothing if it is a space
        else if((s[i].back() >= '0' && s[i].back() <= '9')) { result += s[i]; result += " "; } // If the index char is an operand, add it to output string.
        else if(s[i].back() == '(') { st = st->push('('); } // If the scanned character is an '(', push it to the stack.
        else if(s[i].back() == ')') { // If the index char is an ')', pop and to output string from the stack until an '(' appears.
          while(st->getValue() != 'N' && st->getValue() != '(') {
            char c = (char)st->pop();              
            result += c;
            result += " ";
          }
          if(st->getValue() == '(') {
              char c = (char) st->pop();
          }
        } else { // If an operator is at index
            while(st->getValue() != 'N' && isLower(s[i].back(), st->getValue()) && st->getValue() != '(') {
                char c = (char)st->pop();
                result += c;
                result += " ";
            }
            st = st->push(s[i].back());
        } 
      }
      while(st->getValue() != 'N') { // Pop all the remaining elements from the stack
          char c = (char)st->pop();
          result += c;
          result += " ";
      }
      return result;    
    }

    int eval(string postfix) { // does postfix
      stringstream iss(postfix);
      string number;
      vector<string> tokens;
      while ( iss >> number ) {
        tokens.push_back( number );
      }

      Stack* stack = new Stack(); // Creates a stack which will be responsible for the postfix operations
      for (int i = 0; i < tokens.size(); i++) {
        string temp = tokens.at(i); // Gets the token in question
        if (temp.compare("+") == 0) { // Checks for addition
          int A = stack->pop();
          int B = stack->pop();
          stack = stack->push(A + B);
        } else if (temp.compare("-") == 0) { // Checks for subtraction
          int A = stack->pop();
          int B = stack->pop();
          stack = stack->push(B - A);
        } else if (temp.compare("*") == 0) { // Checks for multiplication
          int A = stack->pop();
          int B = stack->pop();
          stack = stack->push(A * B);
        } else if (temp.compare("/") == 0) { // Checks for division
          int A = stack->pop();
          int B = stack->pop();
          stack = stack->push((int)(B / A));
        } else { // Not an operator so a number
          stack = stack->push(stoi(temp));
        }
      }
      return stack->pop(); // Returns the final leftover item in the stack, which is the result of the operations
    }

    //returns true if c1 has lower or equal precedence than c2
    bool isLower(char c1, char c2){
      return rankChar(c1) <= rankChar(c2);
    }
};

int main() {
  Infix infix = Infix(); // used to solve

  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string inputName;
  cin >> inputName;

  string line;
  ifstream fileInput(inputName); // Creates an input stream
  ofstream fileOutput;  
  int trialIndex = 0; // count trial number
  if (fileInput.is_open()) { // open file
    fileOutput.open("result.txt");
    // fileOutput << "Infix    -->    Postfix    -->    Evaluate\n";
    while ( getline (fileInput, line) ) { // get lines
      string outputInfix = infix.infixToPostfix(line);
      int outputPostfix = infix.eval(outputInfix);
      fileOutput << line << "\t\t\t\t" << outputInfix << "\t\t\t\t" << outputPostfix << endl; // outputs to txt
      trialIndex += 1;
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}