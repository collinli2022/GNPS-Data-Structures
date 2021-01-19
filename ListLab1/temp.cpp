// Collin Li
// Data Structures
// 12/8/2020 
// ComplexNumber Header File  

// Preprocessor directive
#include <iostream>
#include <string>
#include <cmath>
#include <sstream> // new include for ostringstream
using namespace std;

// header guards
#ifndef LISTLAB1_H
#define LISTLAB1_H

class ListNode {
	private:
		string value;
		ListNode* next;
	public:
		ListNode() { }
		ListNode(string a);
		ListNode(string a, ListNode* b);
		
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
		
		string getValue() { return value; }
		ListNode* getNext() { return next; }
};

ListNode::ListNode(string a) {
	value = a;
}

ListNode::ListNode(string a, ListNode* b) {
	value = a;
	next = b;
}

ListNode* ListNode::copyNode(ListNode* arg)  {
    ListNode* other = new ListNode();
    other->value = arg->value;
    other->next = arg->next;
    return other;
}

ListNode* ListNode::copyList(ListNode* arg) {
	if(arg == NULL) {
        return NULL;
    }
    ListNode* other = arg->copyNode(arg);
    other->next = other->copyList(arg->next);
    return other;
}

ListNode* ListNode::rest(ListNode* arg) {
    if(arg == NULL) {
        return NULL;
    }
    ListNode* other = arg->copyNode(arg->next);
    other->next = other->rest(other->next);
    return other;
}


string ListNode::first(ListNode* head) {
	return head->value;
}

string ListNode::second(ListNode* head) {
	ListNode* noFirst = head->rest(head);
	return noFirst->first(noFirst);
}

ListNode* ListNode::pointerToLast(ListNode* head) {
	if(head == NULL) {
		return NULL;
	} else if(head->next == NULL) {
		return head;
	}
	return head->pointerToLast(head->next);
}

ListNode* ListNode::copyOfLast(ListNode* arg) {
	return arg->copyNode(arg->pointerToLast(arg));
}

ListNode* ListNode::insertFirst(ListNode* head, string arg) {
	ListNode* newNode = new ListNode(arg, head);
	return newNode;
}

ListNode* ListNode::insertLast(ListNode* head, string arg) {
	ListNode* last = head->pointerToLast(head);
	ListNode* newNode = new ListNode(arg, NULL);
	last->next = newNode;
	return head;
}

void printMe(ListNode* head)
{
	cout << "[";
	while(head != NULL)
	{
		 cout << head->getValue();
		 head = head->getNext();
		 if(head != NULL)
			 cout << ", ";
	}
	cout << "]" << endl;
}


int main()
{
	ListNode* head = new ListNode("hello", NULL);
	head = new ListNode("foo", head);
	head = new ListNode("boo", head);
	head = new ListNode("nonsense", head);
	printMe(head);
	head = new ListNode("computer", new ListNode("science", new ListNode("c++", new ListNode("coffee", head))));
	
	printMe(head);
	
	ListNode* a = head->copyNode(head);
	cout << "The head has a value \"" << head->getValue() << "\" at " << head << endl;
	cout << "The copy of head has a value of \"" << a->getValue() << "\" at " << a << endl;
	
	
	cout << "Copy the list: " << endl;
	ListNode* copy = head->copyList(head);
	printMe(copy);
	
	cout << "The rest of the list: " << endl;
	ListNode* theRest = head->rest(copy);
	printMe(theRest);

	
	
	cout << "First of the rest = " << head->first(theRest) << endl;
	cout << "Second of the rest = " << head->second(theRest) << endl;
	
	
	ListNode* p = head->pointerToLast(theRest);
	cout << "Pointer to Last = " << p->getValue()+ " at " << p << endl;
	ListNode* c = head->copyOfLast(theRest);
	cout << "Copy of Last =    " << c->getValue()+ " at " << c << endl;




	cout << "Insert what? " << endl;
	string x;
	getline(cin, x);
	theRest = head->insertFirst(theRest, x);
	theRest = head->insertLast(theRest, x);
	printMe(theRest);
	
	return 0;
}

#endif
