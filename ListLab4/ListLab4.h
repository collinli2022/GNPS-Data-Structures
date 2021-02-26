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
    ListNode(string a="", ListNode* b=NULL, ListNode* n=NULL); // constructor

    //inserts a Node into LinkedList
    ListNode* add(ListNode* theRest, ListNode* addition=new ListNode(), int position=0);
    ListNode* add(ListNode* theRest, string y, int position=0);

    //deletes a node from LinkedList
    ListNode* remove(ListNode* theRest, int position=0);

    // Getters
    string getValue() { return value; }
    ListNode* getNext() { return next; }
    ListNode* getPrevious() { return previous; }
    
    void printForward(ListNode* head);
    void printBackward(ListNode* head);

    ~ListNode() { delete next; } // deconstructor that deletes pointer
};

ListNode::ListNode(string a, ListNode* b, ListNode* n) { // sets string and pointers
  value = a;
  previous = b; 
  next = n;
}

ListNode* ListNode::add(ListNode* theRest, ListNode* addition, int position) { // alteration for add method
  if(theRest == NULL) { return addition; }
  
  if(position < 0 || position > theRest->length(theRest)) { // out of bounds; position CAN be equal to length() because adding an index
    cout << "ERROR: Index out of Bounds" << endl; 
    return theRest;
  }

  if(position == 0) { // hard code case
    addition->next = theRest;
    addition->previous = theRest->previous;
    if(theRest->next == NULL) { // length of list is 1
      theRest->previous = addition;
      theRest->next = addition;
      addition->previous = theRest;
    } else { // length of list is > 1
      theRest->previous->next = addition;
      theRest->previous = addition;
    } 

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
  } else { // this is last node
    addition->next = theRest;
    theRest->previous = addition;
  }
  
  return theRest;
}

ListNode* ListNode::add(ListNode* theRest, string y, int position) { // different type of add method call
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
        delete theRest;
        return secondNode;
      } else { // need to make sure new head node links to last node AND last node link to new head node 
        ListNode* secondNode = theRest->next; // Set the reference to the first node to point to the second node
        secondNode->previous = theRest->previous;
        theRest->previous->next = secondNode;
        theRest->next = nullptr; // Set the nextNode reference of oldNode to null
        theRest->previous = nullptr;
        theRest = nullptr;
        delete theRest;
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

void ListNode::printForward(ListNode* head) {
  if(head == NULL) { // if null then print null
    cout << "[NULL]" << endl;
  } else if(head->next == NULL) { // if only one node then print that node
    cout << "[" << head->value << "]" << endl;
  } else {
    ListNode* orig = head; // starting point
    string returnStr = "[";
    do { // Traverse list
      returnStr += head->value;
      head = head->next; // go fowards
      if(head != NULL && orig != head) { returnStr += ", "; }
    } while(head != NULL && orig != head); // when return to starting point end
    returnStr += "]";
    cout << returnStr << endl;
  }
}

void ListNode::printBackward(ListNode* head) {
  if(head == NULL) { // if null then print null
    cout << "[NULL]" << endl;
  } else if(head->previous == NULL) { // if only one node then print that node
    cout << "[" << head->value << "]" << endl;
  } else {
    ListNode* orig = head; // starting point
    string returnStr = "[";
    do { // Traverse list
      returnStr += head->value;
      head = head->previous; // go backwards
      if(head != NULL && orig != head) { returnStr += ", "; }
    } while(head != NULL && orig != head); // when return to starting point end
    returnStr += "]";
    cout << returnStr << endl;
  }
}

ostream& operator << (ostream& os, ListNode* head) { // similar to the printMe method
  string returnStr = "";
  if(head == NULL) {
    returnStr = "[NULL]";
  } else if(head->getNext() == NULL) {
    returnStr = "[" + head->getValue() + "]";
  } else {
    ListNode* orig = head;
    returnStr = "[";
    do { // Traverse list
      returnStr += head->getValue();
      head = head->getNext();
      if(head != NULL && orig != head)
          returnStr += ", ";
    } while(head != NULL && orig != head);
    returnStr += "]";
  }
  return os << returnStr; // return string kindof
}

#endif