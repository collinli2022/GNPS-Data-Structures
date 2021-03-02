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
  public:
    ListNode(int a, ListNode* b=NULL, ListNode* n=NULL); // constructor

    int simulate(ListNode* head, int cycleLength); // returns the winner name

    //inserts a Node into LinkedList
    ListNode* add(ListNode* head, string y, int position=0);

    ListNode* create(int length);

    //deletes a node from LinkedList
    ListNode* remove(ListNode* head, int position=0);
    ListNode* remove(ListNode* head, ListNode* node);

    // Getters
    int getIndex() { return index; }
    ListNode* getNext() { return next; }
    ListNode* getPrevious() { return previous; }

    int length(ListNode* head); // helper method to get length of LinkedList

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
  }
  return head;
}

int ListNode::simulate(ListNode* head, int cycleLength) {
  int participants = head->length(head);
  while(participants > 1) { // keep playing till winner

    for(int i = 0; i < cycleLength; i++) { // Duck (+1) Duck (+1) Goose (*)
      head = head->next;
    }

    // remove current head node
    ListNode* next = head->next;
    head->previous->next = head->next; // previous node's next is head's next
    head->next->previous = head->previous; // next node's previous is head's previous
    head = nullptr;
    head = next;
    participants -= 1;
    
    cout << head->length(head) << endl;
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

/*
Write a program called DuckDuckGoose that first prompts the user for the name of a file and then performs the DuckDuckGoose algorithm from Intro to Programming. The txt file will contain a series of runs of the program. The first line for each run is the number of participants and the second line is the cycle. The cycle number does not need to be less than the number of participants, but both will be positive values. Your program must output the trial number followed by a colon and a single space and then the position of the trial winner, one trial per line, in a new text file called "result.txt" that is created by your program. Your program MUST use a circular linked list to run each trial. Standard rules apply for formatting and usability. 4 points for documentation, 4 points for user-friendliness, 24 points for the required functionality (file read, linked list, file write, correct result for each trial).
*/

int main() {
  // testing
  ListNode* head = new ListNode(0);
  head = head->create(20);
  cout << head->length(head) << endl;
  cout << head->simulate(head, 3) << endl;
  
  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string fileName;
  cin >> fileName;

  ListNode* words = NULL; // will represent head of linked list containing words

  string line;
  ifstream myfile (fileName);
  if (myfile.is_open()) { // open file
    while ( getline (myfile, line) ) { // get lines
      int participants = stoi(line);
      getline (myfile, line);
      int cycle = stoi(line);
      
    }
    myfile.close();
  } else { cout << "Unable to open file"; }

  return 0;
}