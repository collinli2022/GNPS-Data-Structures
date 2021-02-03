// Collin Li
// Data Structures
// 01/27/2020
// MiniProject WordCount 

#include <iostream>
#include <fstream>
#include<bits/stdc++.h> 
using namespace std;

class ListNode {
	private:
		string value;
		ListNode* next;
    int appear;
	public:
		ListNode(string a="", ListNode* b=NULL);
		
		//adds word to Linked List and if there is duplicate then add to number of times repeated
		ListNode* add(ListNode* head, string word);

    ListNode* removeFirstNode(ListNode* head);

		// Getters
		string getValue() { return value; }
    int getAppear() { return appear; }
		ListNode* getNext() { return next; }

    // print List
    void printMe(ListNode* head); 
    void toTXT(ListNode* head, string output="result");
		
		~ListNode() { // deconstructor that deletes pointer
      next = nullptr;
      delete next;
    } 
};

ListNode::ListNode(string a, ListNode* b) { // sets string and pointer
	value = a; 
	next = b;
  appear = 1;
}

ListNode* ListNode::add(ListNode* head, string word) {
  if(value == " ") { // this List is empty so just make this node the head
    cout << "START" << endl;
    value = word;
    return head;
  }

  ListNode* pos = head;
  ListNode* before = NULL;

  // 0 - means need to add new Node to end
  // 1 - means found node with same string word
  // 2 - means need to add node at beginning or in middle
  int operation = 0; 
  while(pos!= NULL) { // iterate through Linked List to find right index
    int x = word.compare(pos->getValue());
    // cout << " : " << word << "_" << pos->getValue() << x;
    if(x > 0) { // keep going down list
      before = pos;
      pos = pos->next;
    } else if(x < 0) { // put right before pos node
      operation = 2;
      break;
    } else { // equal
      pos->appear = pos->getAppear() + 1;
      operation = 1;
      break;
    }
  }
  
  if(operation == 0) {
    ListNode* newNode = new ListNode(word, NULL);
    before->next = newNode;
  } else if(operation == 2) {
    if(before != NULL) { // need to add new node in middle
        ListNode* newNode = new ListNode(word, before->next);
        before->next = newNode;
    } else { // need to add new node in beginning
        ListNode* newNode = new ListNode(word, head);
        return newNode;
    }
  }

  return head;
}

ListNode* ListNode::removeFirstNode(ListNode* head) {
  ListNode* secondNode = head->next; // Set the reference to the first node to point to the second node
  head->next = nullptr; // Set the nextNode reference of oldNode to null
  return secondNode;
}

void ListNode::printMe(ListNode* head) {
    cout << "[";
    while(head != NULL)
    {
         cout << head->getValue() << " (" << head->appear << ")";
         head = head->getNext();
         if(head != NULL)
             cout << ", ";
    }
    cout << "]" << endl;
}

void ListNode::toTXT(ListNode* head, string output) {
  output += ".txt";
  ofstream myfile;
  myfile.open (output);

  while(head != NULL) {
    myfile << head->getValue() << " (" << head->appear << ")\n";
    head = head->getNext();
  }

  myfile.close();
}

/*
Write a program called WordCount that first prompts the user for the name of a file and then performs a count of the number of times a word appears in the file. There will be no punctuation, but there can be numbers. Assume words are not case-sensitive here (in other words, "HeLlO" and "hello" are the same word). At the end of the program, display the list of words in alphabetical order, one word and its count per line, in a new text file that is named "result.txt" (and is created by your program). Your program MUST use Linked Lists to store the words. Standard rules apply for formatting and usability. 4 points for documentation, 4 points for user-friendliness, 22 points for the required functionality (file read, linked list, file write, words properly sorted and counted).
*/


int main () {
  // first prompts the user for the name of a file
  cout << "program starting..." << endl;
  cout << "Enter the name of the file: ";
  string fileName;
  cin >> fileName;
  fileName += ".txt";

  ListNode* words = new ListNode(); 

  string line;
  ifstream myfile (fileName);
  if (myfile.is_open()) {
    while ( getline (myfile, line) ) {
      transform(line.begin(), line.end(), line.begin(), ::tolower); // to lower case
      
      // Used to split string around spaces.
      istringstream ss(line);
 
      string word; // for storing each word
     
      // Traverse through all words
      // while loop till we get 
      // strings to store in string word
      while (ss >> word) {
        words->add(words, word);
      }
    }

    // remove first Node which has a value of ""
    if(words->getNext() != NULL) {
      words = words->removeFirstNode(words);
      words->printMe(words);
      words->toTXT(words);
    }

    myfile.close();
    } else { cout << "Unable to open file"; }
  return 0;
}