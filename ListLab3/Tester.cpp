#include <iostream>
#include <string>
#include "ListLab3.h"
using namespace std;
void printComplex(ListNode* head)
{
  if (head == NULL)
  {
    cout << "[NULL]" << endl << endl;
    return;
  }
	cout << "[";
	while(head != NULL)
	{
    if (head->getPrevious() == NULL && head->getNext() == NULL)
		  cout << (void *)head << ":\t" << head->getValue() << "\t(Next: NULL     \t& Previous: NULL)";
    else if (head->getPrevious() == NULL)
		  cout << (void *)head << ":\t" << head->getValue() << "\t(Next: " << (void *)head->getNext() << "\t& Previous: NULL)";
    else if (head->getNext() == NULL)
		  cout << (void *)head << ":\t" << head->getValue() << "\t(Next: NULL     \t& Previous: " << (void *)head->getPrevious() << ")";
    else
		  cout << (void *)head << ":\t" << head->getValue() << "\t(Next: " << (void *)head->getNext() << "\t& Previous: " << (void *)head->getPrevious() << ")";
		head = head->getNext();
		if(head == NULL)
      cout << "]" << endl << endl;
    else
		  cout << "," << endl;
	}
}
/*
int main()
{
 
  ListNode* head = new ListNode("base", NULL, NULL);
  //printComplex(head);
  cout << "test" << endl;
  cout << head << endl << endl;
  cout << "test" << endl;
  head = head->add(head, "added");
  //printComplex(head);
  cout << head << endl << endl;
  head = head->add(head, "filler", 2);
  //printComplex(head);
  cout << head << endl << endl;

  ListNode* copy = head->copyList(head);
  cout << "This is a copy of the list." << endl;
  //printComplex(copy);
  cout << copy << endl << endl;

  ListNode* theRest = head->rest(head);
  cout << "This is the rest of the list." << endl;
  //printComplex(theRest);
  cout << theRest << endl << endl;
  string str1 = theRest->first(theRest);
  string str2 = theRest->second(theRest);
  //cout << "First: " << str1 << " & Second: " << str2 << endl << endl;

  head = head->addLast(head, "fiddle");
  head = head->addFirst(head, "start");
  //printComplex(head);

  head = head->remove(head, 2);
  //printComplex(head);
  head = head->remove(head);
  //printComplex(head);
  cout << head << endl << endl;

  cout << "Add what?" << endl;
    string y;
  cin >> y;
    cout << "Add where?" << endl;
    int position;
    cin >> position;
  head = head->add(head, y, position);
  //printComplex(head);
  cout << head << endl << endl;

  cout << "Remove which element?" << endl;
    cin >> position;
    head = head->remove(head, position);
    //printComplex(head);
  cout << head << endl << endl;

  //printComplex(head);
  cout << head << endl << endl;

  head = head->add(head, "nope");
  //printComplex(head);
  cout << head << endl << endl;

  return 0;
}
*/

int main()
{
  ListNode* head = new ListNode("base", NULL, NULL);
  head = head->add(head, "added");
  printComplex(head);
  head = head->add(head, "filler", 2);
  printComplex(head);

  ListNode* copy = head->copyList(head);
  cout << "This is a copy of the list." << endl;
  printComplex(copy);

  ListNode* theRest = head->rest(head);
  
  cout << "This is the rest of the list." << endl;
  printComplex(theRest);
  string str1 = theRest->first(theRest);
  string str2 = theRest->second(theRest);
  cout << "First: " << str1 << " & Second: " << str2 << endl << endl;

  head = head->addLast(head, "fiddle");
  head = head->addFirst(head, "start");
  printComplex(head);

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

  cout << "Remove which element?" << endl;
	cin >> position;
	head = head->remove(head, position);
	printComplex(head);

  head = head->remove(head);
  head = head->remove(head);
  head = head->remove(head); //head = head->remove(head, 10000); //Very extreme edge case
  printComplex(head);

  head = head->add(head, "nope");
  printComplex(head);

  return 0;
}
