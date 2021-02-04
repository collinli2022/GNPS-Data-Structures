// Collin Li
// Data Structures
// 01/27/2020
// MiniProject WordCount 

#include <iostream>
#include <fstream>
#include<bits/stdc++.h> 
using namespace std;

// Linked Lists to store the words
class ListNode {
	private:
		string value; // store the word
		ListNode* next;
    int appear; // store the number of times appear
	public:
		ListNode(string a="", ListNode* b=NULL);
		
		//adds word to Linked List and if there is duplicate then add to number of times repeated
		ListNode* add(ListNode* head, string word);

    /* // Not really needed
    ListNode* removeFirstNode(ListNode* head);
    */

		// Getters
		string getValue() { return value; }
    int getAppear() { return appear; }
		ListNode* getNext() { return next; }

    // print list
    void printMe(ListNode* head); 
    void toTXT(ListNode* head, string output="result");
		
		~ListNode() { // deconstructor that deletes pointer
      next = nullptr;
      delete next;
    } 
};

ListNode::ListNode(string a, ListNode* b) { // sets string and pointer and appear
	value = a; 
	next = b;
  appear = 1;
}

ListNode* ListNode::add(ListNode* head, string word) {
  ListNode* pos = head; 
  ListNode* before = NULL; // will store the previous node

  // 0 - means need to add new Node to end
  // 1 - means found node with same string word
  // 2 - means need to add node at beginning or in middle
  int operation = 0; 
  while(pos != NULL) { // iterate through Linked List to find right index
    int x = word.compare(pos->getValue());
    if(x > 0) { // keep going down list since word is later
      before = pos;
      pos = pos->next;
    } else if(x < 0) { // put right before pos node
      operation = 2;
      break;
    } else { // same word
      pos->appear = pos->getAppear() + 1; // increase appear
      operation = 1;
      break;
    }
  }
  
  if(operation == 0) { // add new node to end
    ListNode* newNode = new ListNode(word, NULL);
    before->next = newNode; // pos is NULL so before is last Node
  } else if(operation == 2) { // add node beginning or middle of list
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

/*
ListNode* ListNode::removeFirstNode(ListNode* head) {
  ListNode* secondNode = head->next; // Set the reference to the first node to point to the second node
  head->next = nullptr; // Set the nextNode reference of oldNode to null
  return secondNode;
}
*/

void ListNode::printMe(ListNode* head) { // for debugging purposes
    cout << "[";
    while(head != NULL) {
         cout << head->getValue() << " (" << head->appear << ")";
         head = head->getNext();
         if(head != NULL) { cout << ", "; };
    }
    cout << "]" << endl;
}

void ListNode::toTXT(ListNode* head, string output) { // output text file
  output += ".txt";
  ofstream myfile;
  myfile.open (output);
  while(head != NULL) { // Traverse through linked list and outputing each word and occurance
    myfile << head->getValue() << " " << head->appear << "\n";
    head = head->getNext();
  }
  myfile.close();
}

/*
Write a program called WordCount that first prompts the user for the name of a file and then performs a count of the number of times a word appears in the file. There will be no punctuation, but there can be numbers. Assume words are not case-sensitive here (in other words, "HeLlO" and "hello" are the same word). At the end of the program, display the list of words in alphabetical order, one word and its count per line, in a new text file that is named "result.txt" (and is created by your program). Your program MUST use Linked Lists to store the words. Standard rules apply for formatting and usability. 4 points for documentation, 4 points for user-friendliness, 22 points for the required functionality (file read, linked list, file write, words properly sorted and counted).
*/


int main () {
  // first prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string fileName;
  cin >> fileName;
  fileName += ".txt"; ASK IF Mrs.ZINN wants to enter the .txt or not

  ListNode* words = NULL; // will represent head of linked list containing words

  string line;
  ifstream myfile (fileName);
  if (myfile.is_open()) { // open file
    while ( getline (myfile, line) ) { // get lines
      transform(line.begin(), line.end(), line.begin(), ::tolower); // to lower case
      
      istringstream ss(line); // Used to split string around spaces.
 
      string word; // for storing each word
     
      while (ss >> word) { // loop through all words in line
        if(words == NULL) { // if Linked List is empty, add first word
          words = new  ListNode(word);
        } else { // add word
          words->add(words, word);
        }
      }
    }

    if(words->getNext() != NULL) { // make sure  Linked List is not empty
      //words->printMe(words);
      words->toTXT(words);
    } else {
      cout << "Linked List is empty" << endl; // could be because nothing in input txt
    }

    myfile.close();
    } else { cout << "Unable to open file"; }
  return 0;
}