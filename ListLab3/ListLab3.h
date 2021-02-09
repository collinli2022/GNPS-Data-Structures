// Collin Li
// Data Structures
// 02/09/2021
// ListLab3 header file

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;

// header guards
#ifndef LISTLAB3_H
#define LISTLAB3_H

/*
Create ListLab3.h that demonstrates a doubly-linked list. Your file must include methods to add a node at the beginning or specified position of the list (called add...no parameter is beginning; parameter is position) and remove a node at the beginning or specified position of the list (called remove; same information as above). Standard rules apply for formatting and usability. 4 points for documentation, 4 points for user-friendliness, 20 points for the required methods. You must also include operators for displaying your list when printed with cout.
*/

class ListNode {
	private:
		string value;
    ListNode* before;
		ListNode* next;
	public:
		ListNode(string a="", ListNode* before=NULL, ListNode* after=NULL);
		
    //inserts a Node into LinkedList (no parameter is beginning; parameter is position)
		ListNode* add(ListNode* head, string arg, int position=0);

    //deletes a node from LinkedList
    ListNode* remove(ListNode* theRest, int position=0);
		
		// Getters
		string getValue() { return value; }
		ListNode* getNext() { return next; }
		
		~ListNode() { delete next; } // deconstructor that deletes pointer
};

ListNode::ListNode(string a, ListNode* b, ListNode* n) { // sets string and pointers
	value = a;
  before = b; 
	next = n;
}

ListNode* ListNode::add(ListNode* head, string arg, int position=0) {
  if(position < 0 || position > theRest->length(theRest)) { // out of bounds; position CAN be equal to length() because adding an index
    cout << "ERROR: Index out of Bounds" << endl; 
    return head;
  }

  if(position == 0) {
    ListNode* newHead = new ListNode(arg, NULL, head);
    head->before = newHead;
    return newHead;
  }

  ListNode* beforeInsert = head;
  // traverse the list until it is pointing to the node before where the new node will be inserted (currentNode)
  for(int i = 0; i < position-1; i++) { // position-1 because we want the insertedNode to be at that position
    if(beforeInsert->next != NULL) {
      beforeInsert = beforeInsert->next;
    } else {
      cout << "ERROR: Index out of Bounds" << endl; 
    }
  }

}

#endif