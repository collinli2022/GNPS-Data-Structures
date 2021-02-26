#include <iostream>
#include <string>
#include "ListLab4.h"
using namespace std;
void printComplex(ListNode* head)
{
  ListNode* orig = head;
  if (head == NULL)
  {
    cout << "NULL" << endl;
    return;
  }
  cout << "[";
  do
  {
    if (head->getPrevious() == NULL && head->getNext() == NULL)
    	  cout << (void*)head << ":\t" << head->getValue() << "\t(Next: NULL     \t& Previous: NULL)";
    else if (head->getPrevious() == NULL)
    	  cout << (void*)head << ":\t" << head->getValue() << "\t(Next: " << (void*)head->getNext() << "\t& Previous: NULL)";
    else if (head->getNext() == NULL)
    	  cout << (void*)head << ":\t" << head->getValue() << "\t(Next: NULL     \t& Previous: " << (void*)head->getPrevious() << ")";
    else
    	  cout << (void*)head << ":\t" << head->getValue() << "\t(Next: " << (void*)head->getNext() << "\t& Previous: " << (void*)head->getPrevious() << ")";
  	head = head->getNext();
  	if(head == orig || head == NULL)
      cout << "]" << endl;
    else 
      cout << "," << endl;
  } while(orig != head && head != NULL);
}
int main()
{
  ListNode* head = new ListNode("base", NULL, NULL);
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;

  head = head->add(head, "added", 0);
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;

  head = head->add(head, "filler", 1);
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;

  head = head->add(head, "some", 3);
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;

  head = head->add(head, "more");
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;
  
  head = head->remove(head, 2);
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;

  head = head->remove(head);
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;
  /*
  cout << "Add what?" << endl;
	string y;
  cin >> y;
	cout << "Add where?" << endl;
	int position;
	cin >> position;
  head = head->add(head, y, position);
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;

  cout << "Remove which element?" << endl;
	cin >> position;
	head = head->remove(head, position);
	printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;
	*/
  head = head->remove(head);
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;

  head = head->remove(head);
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;

  head = head->remove(head);
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;

  head = head->add(head, "nope");
  printComplex(head);
  head->printForward(head);
  head->printBackward(head);
  cout << head << "(cout)" << endl << endl;

  return 0;
}