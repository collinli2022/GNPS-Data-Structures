// Collin Li
// Data Structures
// 03/01/2021
// DuckDuckGoose MiniProject 

// Preprocessor directive
#include <iostream>
#include <string>
#include <fstream>
#include<bits/stdc++.h> 
using namespace std;

class ListNode {
  private:
    int index;
    ListNode* previous;
    ListNode* next;
    int length(ListNode* head); // helper method to get length of LinkedList
  public:
    ListNode(int a, ListNode* b=NULL, ListNode* n=NULL); // constructor

    int simulate(ListNode* head, int cycleLength); // returns the winner name

    ListNode* create(int length);

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

ListNode* ListNode::create(int length) {
  ListNode* head = new ListNode(0);
  ListNode* index = head;
  for(int i = 1; i < length; i++) {
    ListNode* temp = new ListNode(i);
    temp->previous = index;
    temp->next = head;

    index->next=temp;
    index = index->next;
    
    if(i == length-1) {
      head->previous = temp;
    }
    
  }
  return head;
}

int ListNode::simulate(ListNode* head, int cycleLength) {
  int participants = head->length(head);
  while(participants > 1) { // keep playing till winner

    // head->print(head);

    for(int i = 0; i < cycleLength-1; i++) { // Duck (+1) Duck (+1) Goose (*)
      head = head->next;
    }

    // remove current head node
    ListNode* next = head->next;
    head->previous->next = head->next; // previous node's next is head's next
    head->next->previous = head->previous; // next node's previous is head's previous
    head = nullptr;
    head = next;
    participants -= 1;
    
    
  }
  return head->index; // should just be one remaining
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
Write a program called DuckDuckGoose that first prompts the user for the name of a file and then performs the DuckDuckGoose algorithm from Intro to Programming. The txt file will contain a series of runs of the program. The first line for each run is the number of participants and the second line is the cycle. The cycle number does not need to be less than the number of participants, but both will be positive values. Your program must output the trial number followed by a colon and a single space and then the position of the trial winner, one trial per line, in a new text file called "result.txt" that is created by your program. Your program MUST use a circular linked list to run each trial. Standard rules apply for formatting and usability. 4 points for documentation, 4 points for user-friendliness, 24 points for the required functionality (file read, linked list, file write, correct result for each trial).
*/

// for debugging purposes only
void printComplex(ListNode* head) {
  ListNode* orig = head;
  if (head == NULL) { cout << "NULL" << endl; return; }
  cout << "[";
  do {
    if (head->getPrevious() == NULL && head->getNext() == NULL)
    	  cout << (void*)head << ":\t" << head->getIndex() << "\t(Next: NULL     \t& Previous: NULL)";
    else if (head->getPrevious() == NULL)
    	  cout << (void*)head << ":\t" << head->getIndex() << "\t(Next: " << (void*)head->getNext() << "\t& Previous: NULL)";
    else if (head->getNext() == NULL)
    	  cout << (void*)head << ":\t" << head->getIndex() << "\t(Next: NULL     \t& Previous: " << (void*)head->getPrevious() << ")";
    else
    	  cout << (void*)head << ":\t" << head->getIndex() << "\t(Next: " << (void*)head->getNext() << "\t& Previous: " << (void*)head->getPrevious() << ")";
  	head = head->getNext();
  	if(head == orig || head == NULL)
      cout << "]" << endl;
    else 
      cout << "," << endl;
  } while(orig != head && head != NULL);
}

int main() {
  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string inputName;
  cin >> inputName;

  ListNode* words = NULL; // will represent head of linked list containing words

  string line;
  ifstream fileInput(inputName);
  ofstream fileOutput;
  fileOutput.open("result.txt");
  
  int trialIndex = 0;
  if (fileInput.is_open()) { // open file
    while ( getline (fileInput, line) ) { // get lines
      int participants = stoi(line); // get num of participants
      getline (fileInput, line);
      int cycle = stoi(line); // get cycle length
      
      ListNode* head = new ListNode(0);
      head = head->create(participants); // create List of participants length
      string output = to_string(trialIndex);
      output += ": ";
      output += to_string(head->simulate(head, cycle)); // get winner
      // cout << output << endl; // <-- debug
      fileOutput << output << "\n";
      trialIndex += 1;
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}