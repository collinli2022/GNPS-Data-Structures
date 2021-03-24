// Collin Li
// Data Structures
// 03/22/2021
// Postfix Project 

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

class Postfix {
  private:
  public:
    Postfix() {};

    string simulate(vector<string> tokens) {
      Stack* stack = new Stack(); //Creates a stack which will be responsible for the postfix operations
      for (int i = 0; i < tokens.size(); i++) {
        
        string temp = tokens.at(i); //Gets the token in question
        if (temp.compare("+") == 0) { //Checks for addition
          int A = stack->pop();
          int B = stack->pop();
          stack = stack->push(A + B);
        }
        else if (temp.compare("-") == 0) { //Checks for subtraction
          int A = stack->pop();
          int B = stack->pop();
          stack = stack->push(B - A);
        } else if (temp.compare("*") == 0) { //Checks for multiplication
          int A = stack->pop();
          int B = stack->pop();
          stack = stack->push(A * B);
        } else if (temp.compare("/") == 0) { //Checks for division
          int A = stack->pop();
          int B = stack->pop();
          stack = stack->push(B / A);
        } else if (temp.compare("%") == 0) { //Checks for modulus
          int A = stack->pop();
          int B = stack->pop();
          stack = stack->push(B % A);
        } else if (temp.compare("^") == 0) { //Checks for exponents
          int A = stack->pop();
          int B = stack->pop();
          if(i == tokens.size()-1) {
            return to_string(pow(B,A));
          } else {
            stack = stack->push((int)pow(B, A));
          }
        } else if (temp.compare("!") == 0) { //Checks for factorial
          int A = stack->pop();
          int result = 1;
          for (int i = 1; i <= A; i++) { result *= i; }
          stack = stack->push(result);
        }
        else { // Not an operator so a number
          stack = stack->push(stoi(temp));
        }
      }
      return to_string(stack->pop()); //Returns the final leftover item in the stack, which is the result of the operations
    }
};

int main() {
  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string inputName;
  cin >> inputName;

  Postfix postfix = Postfix(); // used to solve

  string line;
  ifstream fileInput(inputName); // Creates an input stream
  ofstream fileOutput;  
  
  int trialIndex = 0; // count trial number
  if (fileInput.is_open()) { // open file
    fileOutput.open("result.txt");
    while ( getline (fileInput, line) ) { // get lines
      std::stringstream iss( line );
      string number;
      std::vector<string> myNumbers;
      while ( iss >> number ) {
        myNumbers.push_back( number );
      }
      string output = postfix.simulate(myNumbers); // see if grouping of parenthesis is correct

      fileOutput << line << ": " << output << "\n";

      trialIndex += 1;
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}