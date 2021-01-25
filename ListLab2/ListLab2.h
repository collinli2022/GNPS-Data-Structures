// Collin Li
// Data Structures
// 01/19/2021
// ListLab2 header file

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;

// header guards
#ifndef LISTLAB2_H
#define LISTLAB2_H

class ListNode {
	private:
		string value;
		ListNode* next;
    int length(ListNode* head); // helper method to get length of LinkedList
	public:
		ListNode(string a="", ListNode* b=NULL);
		
		ListNode* copyNode(ListNode* arg);
		
		// returns a new list that is a copy of the original list.
		// this method is recursive!
		// example call: ListNode* head2 = head->copyList(head);
		ListNode* copyList(ListNode* arg);
		
		//returns a new linked list containing copies of each node in
		//the original list except the first node, maintaining the
		//order of the original list. It is not correct to just
		//return a pointer to the 2 nd node of the original linked
		//list. This method is recursive.
		ListNode* rest(ListNode* h);
		
		// returns the value of the first node, or NULL if the list is empty
		string first(ListNode* head);
		
		// returns the value of the second node, or NULL if the list is empty or if there is only one node.
		// hint: second could call the first of rest.
		string second(ListNode* head);
		
		//returns a reference to the last node in the list, or NULL if the list is empty.
		ListNode* pointerToLast(ListNode* head);
		
		//returns a copy of the last node (not just its value!). copyofLast can be recursive.
		ListNode* copyOfLast(ListNode* head);
		
		//returns a reference to a list whose first node&#39;s value is specified by the argument, and the
		//first node&#39;s next links to the original list.
		ListNode* insertFirst(ListNode* head, string arg);
		
		//returns a reference to a list whose last node&#39;s value is specified by the argument, such
		//that this last node has been appended to the original list and had its next is set to NULL
		ListNode* insertLast(ListNode* head, string arg);

    //inserts a Node into LinkedList
    ListNode* insertMiddle(ListNode* theRest, string y, int position);

    //deletes a node from LinkedList
    ListNode* remove(ListNode* theRest, int position);
		
		// Getters
		string getValue() { return value; }
		ListNode* getNext() { return next; }
		
		~ListNode() { delete next; } // deconstructor that deletes pointer
};

ListNode::ListNode(string a, ListNode* b) { // sets string and pointer
	value = a; 
	next = b;
}

ListNode* ListNode::copyNode(ListNode* arg)  {
	if(arg == NULL) { 
		return NULL; // ends recursion if arg==NULL
	}
  ListNode* other = new ListNode(); // a new ListNode
  other->value = arg->value;
  other->next = arg->next;
  return other;
}

ListNode* ListNode::copyList(ListNode* arg) {
	if(arg == NULL) { // ends recursion
        return NULL;
  }
  ListNode* other = new ListNode(); // a new ListNode
  other->value = arg->value; // same value
  other->next = arg->copyList(arg->next); // pointer to next will point to a new ListNode with same value
  return other;
}

ListNode* ListNode::rest(ListNode* h) {
  if(h == NULL) { // checks if NULL
    	return NULL;
	} else if(h->next == NULL) { // makes sure next is not NULL
        return NULL;
  }
  return h->copyList(h->next); // returns a copy of the list excluding the head
}

string ListNode::first(ListNode* head) {
	if(head == NULL) { // checks if NULL
		return "NULL";
	}
	return head->value; // returns the value
}

string ListNode::second(ListNode* head) {
	if(head == NULL) { // checks if NULL
		return "NULL";
	}
	ListNode* noFirst = head->rest(head); // rest method excludes the head
	return noFirst->first(noFirst); // return the value of the second node (since the rest method removed the first node)
}

ListNode* ListNode::pointerToLast(ListNode* head) {
	if(head == NULL) { // checks if NULL
		return NULL;
	} else if(head->next == NULL) { // makes sure next is not NULL and if it is, this is the last node
		return head;
	}
	return head->pointerToLast(head->next); // recursion (if head is not the last Node, keep going down the list)
}

ListNode* ListNode::copyOfLast(ListNode* head) {
	return head->copyNode(head->pointerToLast(head)); // returns a copy of the last node
}

ListNode* ListNode::insertFirst(ListNode* head, string arg) {
	ListNode* newNode = new ListNode(arg, head); // creates new node with (string) value of arg & takes place as the head by linking this node's next to the origianl head
	return newNode;
}

ListNode* ListNode::insertLast(ListNode* head, string arg) {
	ListNode* last = head->pointerToLast(head); // gets the pointer to the last node
	ListNode* newNode = new ListNode(arg, NULL); // creates new node with (string) value of arg & this node's next is NULL
	last->next = newNode; // sets the origial last node to link with the new (last) node
	return head;
}

ListNode* ListNode::insertMiddle(ListNode* theRest, string y, int position) {
  if(position < 0 || position > theRest->length(theRest)) { // out of bounds; position CAN be equal to length() because adding an index
    cout << "ERROR: Index of of Bounds" << endl; 
    return theRest;
  }

  if(position == 0) {
    return new ListNode(y, theRest);
  }
  
  ListNode* beforeInsert = theRest;
  // traverse the list until it is pointing to the node before where the new node will be inserted (currentNode)
  for(int i = 0; i < position-1; i++) { // position-1 because we want the insertedNode to be at that position
    if(beforeInsert->next != NULL) {
      beforeInsert = beforeInsert->next;
    } else {
      cout << "ERROR: Index out of Bounds" << endl; 
    }
  }

  ListNode* insertedNode = new ListNode(y, beforeInsert->next); // Set nextNode reference of the new Node to point to the current first node of the linked list
  beforeInsert->next = insertedNode; // Change the reference to the original first node of the list so that it now points to the new node
  
  return theRest;
}

ListNode* ListNode::remove(ListNode* theRest, int position) {
  if(position < 0 || position >= theRest->length(theRest)) { // position out of bounds
    cout << "ERROR: Index out of Bounds" << endl;
    return theRest;
  }

  if(position == 0) { // hard code first case
    if(theRest == NULL) { // if List is empty return NULL
      return NULL;
    } else {
      ListNode* secondNode = theRest->next; // Set the reference to the first node to point to the second node
      theRest->next = nullptr; // Set the nextNode reference of oldNode to null
      return secondNode;
    }
  }

  ListNode* beforeDelete = theRest;
  for(int i = 0; i < position-1; i++) { // Traverse list; go to node before (position-1)
    if(beforeDelete->next != NULL) {
      beforeDelete = beforeDelete->next;
    } else {
      cout << "ERROR: Index out of Bounds" << endl; 
    }
  }
  
  if(beforeDelete->next != NULL) { // last check to make sure desired node to be deleted is not NULL
    ListNode* toDelete = beforeDelete->next;
    beforeDelete->next = toDelete->next; // Change the nextNode pointer of previousNode to point to the node after currentNode
    toDelete->next = nullptr; // set deleted node's next to be null
    toDelete = nullptr; // set deleted null to be next
    delete toDelete;
  }
  
  return theRest;
}

int ListNode::length(ListNode* head) {
  int count = 1; // will be counter - this node is the first node
  ListNode* copy = head;
  while(head->next != NULL) { // keep looping until end of Linked List
    count++; // add to counter
    head=head->next; // move down the linked List
  }
  copy = nullptr;
  delete copy; // delete pointer
  return count;
}

#endif