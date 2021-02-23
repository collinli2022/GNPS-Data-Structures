#include <iostream>
#include <string>
#include "ListLab4.h"
using namespace std;
void printComplex(ListNode* head) {
  
  ListNode* orig = head;
  
  if (head == NULL) {
    cout << "[NULL]" << endl << endl;
    return;
  }
  cout << "[";
  do {
    if (head->getPrevious() == NULL && head->getNext() == NULL)
    	  cout << (void *)head << ":\t" << head->getValue() << "\t(Next: NULL     \t& Previous: NULL)";
    else if (head->getPrevious() == NULL)
    	  cout << (void *)head << ":\t" << head->getValue() << "\t(Next: " << (void *)head->getNext() << "\t& Previous: NULL)";
    else if (head->getNext() == NULL)
    	  cout << (void *)head << ":\t" << head->getValue() << "\t(Next: NULL     \t& Previous: " << (void *)head->getPrevious() << ")";
    else
    	  cout << (void *)head << ":\t" << head->getValue() << "\t(Next: " << (void *)head->getNext() << "\t& Previous: " << (void *)head->getPrevious() << ")";
  	head = head->getNext();
  	if(head == orig || head == NULL)
      cout << "]" << endl;
    else 
      cout << "," << endl;
  } while(orig != head && head != NULL);
  orig->printForward(orig);
  orig->printBackward(orig);
  
}

int main()
{
  cout << "START" << endl << endl;

  ListNode* head = new ListNode("base", NULL, NULL);
  head = head->add(head, "added");
  printComplex(head);
  head = head->add(head, "filler", 2);
  printComplex(head);
  cout << "Length: " << head->length(head) << endl;


  cout << "START1" << endl << endl;

  head = head->remove(head, 2);
  printComplex(head);
  head = head->remove(head);
  printComplex(head);

  cout << "Add what?" << endl;
	string y;
  cin >> y;
	cout << "Add where?" << endl;
	int position;
	cin >> position;
  head = head->add(head, y, position);
  printComplex(head);

  cout << "START2" << endl << endl;
  cout << "Remove which element?" << endl;
	cin >> position;
	head = head->remove(head, position);
	printComplex(head);
	
	cout << "START3" << endl << endl;

  head = head->remove(head);
  head = head->remove(head);
  head = head->remove(head);
  head = head->remove(head);
  head = head->remove(head); //head = head->remove(head, 10000); //Very extreme edge case
  printComplex(head);

  cout << "START4" << endl;

  head = head->add(head, "nope");
  printComplex(head);

  return 0;
}
