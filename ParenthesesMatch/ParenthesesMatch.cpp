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

class ParenMatch
{
  private:
    int index;
    ListNode* previous;
    ListNode* next;
    int length(ListNode* head); // helper method to get length of LinkedList
  public:
    string LEFT = &quot;([{&lt;&quot;;
    string RIGHT = &quot;)]}&gt;&quot;;
    bool checkParen(string s);

    ListNode(int a, ListNode* b=NULL, ListNode* n=NULL); // constructor

    // Getters
    int getIndex() { return index; }
    ListNode* getNext() { return next; }
    ListNode* getPrevious() { return previous; }

    void print(ListNode* head);
    
    ~ListNode() { delete next; } // deconstructor that deletes pointer

};


ListNode::ListNode(int a, ListNode* b, ListNode* n) { // sets string and pointers
  index = a;
  previous = b; 
  next = n;
}


int ListNode::length(ListNode* head) {
  int count = 1; // will be counter - this node is the first node
  ListNode* copy = head;
  if(copy != NULL) {
    copy=copy->next;
  } else {
    return 0;
  }
  while(copy != NULL && copy != head) { // keep looping until end of Linked List
    count++; // add to counter
    copy=copy->next; // move down the linked List
  }
  copy = nullptr;
  delete copy; // delete pointer
  return count;
}

void ListNode::print(ListNode* head) {
  if(head == NULL) { // if null then print null
    cout << "[NULL]" << endl;
  } else if(head->next == NULL) { // if only one node then print that node
    cout << "[" << to_string(head->index) << "]" << endl;
  } else {
    ListNode* orig = head; // starting point
    string returnStr = "[";
    do { // Traverse list
      returnStr += to_string(head->index);
      head = head->next; // go fowards
      if(head != NULL && orig != head) { returnStr += ", "; }
    } while(head != NULL && orig != head); // when return to starting point end
    returnStr += "]";
    cout << returnStr << endl;
  }
}

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
      string equation = stoi(line); // get num of participants
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}