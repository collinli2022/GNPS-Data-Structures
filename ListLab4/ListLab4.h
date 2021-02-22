// Collin Li
// Data Structures
// 02/22/2021
// ListLab4 header file    

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;

// header guards
#ifndef LISTLAB4_H
#define LISTLAB4_H

/*
A circular Linked List is a variation of a Linked List in which the first element points to the last element and the last element points to the first element.

Create ListLab4.h that demonstrates a circular doubly-linked list. Your file must include methods to add a node at a specified position of the list and remove a node at a specified position of the list. In addition, please include methods to printForward from a starting position and printBackward from a starting position (as measured from your insertion point from the beginning of the creation of the list). Standard rules apply for formatting and usability. 4 points for documentation, 4 points for user-friendliness, 20 points for the required methods. You must also include operators for displaying your list when printed with cout.
*/

class ListNode {
  private:
    string value;
    ListNode* previous;
    ListNode* next;
    int length(ListNode* head); // helper method to get length of LinkedList
  public:
    ListNode(string a="", ListNode* b=NULL, ListNode* n=NULL);
    
    ListNode* copyNode(ListNode* arg);
    
    // returns a new list that is a copy of the original list.
    // example call: ListNode* head2 = head->copyList(head);
    ListNode* copyList(ListNode* arg);
    
    //returns a new linked list containing copies of each node in
    //the original list except the first node, maintaining the
    //order of the original list. It is not correct to just
    //return a pointer to the 2nd node of the original linked
    //list. This method is recursive.
    ListNode* rest(ListNode* head);
    
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
    ListNode* addFirst(ListNode* head, string arg);
    
    //returns a reference to a list whose last node&#39;s value is specified by the argument, such
    //that this last node has been appended to the original list and had its next is set to NULL
    ListNode* addLast(ListNode* head, string arg);

    //inserts a Node into LinkedList
    ListNode* add(ListNode* theRest, ListNode* addition=new ListNode(), int position=0);
    ListNode* add(ListNode* theRest, string y, int position=0);

    //deletes a node from LinkedList
    ListNode* remove(ListNode* theRest, int position=0);

    // Getters
    string getValue() { return value; }
    ListNode* getNext() { return next; }
    ListNode* getPrevious() { return previous; }

    ~ListNode() { delete next; } // deconstructor that deletes pointer
};

ListNode::ListNode(string a, ListNode* b, ListNode* n) { // sets string and pointers
  value = a;
  previous = b; 
  next = n;
}

ListNode* ListNode::copyNode(ListNode* arg)  {
  if(arg == NULL) { 
    return NULL; // ends recursion if arg==NULL
  }
  ListNode* other = new ListNode(arg->value, arg->previous, arg->next); // a new ListNode
  return other;
}

ListNode* ListNode::copyList(ListNode* arg) {
  if(arg == NULL) { return NULL; }
  ListNode* copyHead = copyNode(arg); // the new head
  ListNode* copy = copyHead; // use to traverse through Linked List
  while(copy->next != NULL) { // keep looping until end of Linked List
    ListNode* temp = copyNode(copy->next); // make copy
    temp->previous = copy; // assign previous of copy to be the correct previous
    copy->next = temp; 
    copy = copy->next;
  }
  return copyHead;
}

ListNode* ListNode::rest(ListNode* head) {
  if(head == NULL) { // checks if NULL
    return NULL;
  } else if(head->next == NULL) { // makes sure next is not NULL
    return NULL;
  }
  return head->copyList(head->next); // returns a copy of the list excluding the head
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

ListNode* ListNode::addFirst(ListNode* head, string arg) {
  ListNode* newNode = new ListNode(arg, head->previous, head); // creates new node with (string) value of arg & takes place as the head by linking this node's next to the origianl head
  head->previous = newNode;
  
  if(head->length(head) == 2) {
    newNode->previous = head;
  }
  
  return newNode;
}

ListNode* ListNode::addLast(ListNode* head, string arg) {
  ListNode* last = head->pointerToLast(head); // gets the pointer to the last node
  ListNode* newNode = new ListNode(arg, head->pointerToLast(head), head); // creates new node with (string) value of arg & this node's next is head & previous is original last node
  last->next = newNode; // sets the origial last node to link with the new (last) node
  return head;
}

ListNode* ListNode::add(ListNode* theRest, ListNode* addition, int position) { // alteration for add method
    if(theRest == NULL) { return addition; }
  
  if(position < 0 || position > theRest->length(theRest)) { // out of bounds; position CAN be equal to length() because adding an index
    cout << "ERROR: Index out of Bounds" << endl; 
    return theRest;
  }

  if(position == 0) {
      addition->next = theRest;
      theRest->previous = addition;
      return addition;
  }
  
  ListNode* beforeInsert = theRest;
  // traverse the list until it is pointing to the node before where the new node will be inserted (currentNode)
  for(int i = 0; i < position-1; i++) { // position-1 because we want the insertedNode to be at that position
    if(beforeInsert->next != NULL) {
      beforeInsert = beforeInsert->next;
    } else {
      cout << "ERROR: Index out of Bounds" << endl;
      return theRest;
    }
  }

  // Set nextNode reference of the new Node to point to the current first node of the linked list
  addition->previous = beforeInsert;
  addition->next = beforeInsert->next;
  beforeInsert->next = addition; // Change the reference to the original first node of the list so that it now points to the new node
  if(addition->next != NULL) {
    addition->next->previous = addition;
  }
  
  return theRest;
}

ListNode* ListNode::add(ListNode* theRest, string y, int position) {
  return theRest->add(theRest, new ListNode(y), position);
}

ListNode* ListNode::remove(ListNode* theRest, int position) {
  if(position == 0) { // hard code first case
    if(theRest == NULL) { // if List is empty return NULL
      return NULL;
    } else if(theRest->next == NULL) {
      theRest->next = nullptr;
      theRest = nullptr;
      return NULL;
    } else {
      if(theRest->length(theRest) <= 2) { // only one node will remain
        ListNode* secondNode = theRest->next; // Set the reference to the first node to point to the second node
        theRest->next = nullptr; // Set the nextNode reference of oldNode to null
        theRest->previous = nullptr;
        theRest = nullptr;
        secondNode->previous = nullptr;
        secondNode->next = nullptr;
        return secondNode;
      } else { // need to make sure new head node links to last node AND last node link to new head node 
        ListNode* secondNode = theRest->next; // Set the reference to the first node to point to the second node
        secondNode->previous = theRest->previous;
        theRest->previous->next = secondNode;
        theRest->next = nullptr; // Set the nextNode reference of oldNode to null
        theRest->previous = nullptr;
        theRest = nullptr;
        return secondNode;
      }      
    }
  }
  
  if(position < 0 || position >= theRest->length(theRest)) { // position out of bounds
    cout << "ERROR: Index out of Bounds" << endl;
    return theRest;
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
    if(toDelete->next != NULL) {
      toDelete->next->previous = beforeDelete;
    }
    toDelete->previous = nullptr;
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

ostream& operator << (ostream& os, ListNode* head) { // similar to the printMe method
  string returnStr = "[";
  while(head != NULL) { // Traverse list
    returnStr += head->getValue();
    head = head->getNext();
    if(head != NULL)
        returnStr += ", ";
  }
  returnStr += "]";
  return os << returnStr; // return string kindof
}

#endif