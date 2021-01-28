// Collin Li
// Data Structures
// 01/27/2020
// MiniProject WordCount 

#include <iostream>
#include <fstream>
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

		// Getters
		string getValue() { return value; }
		ListNode* getNext() { return next; }

    // Setters
    void addAppear(int add=1);
		
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
  // add word to linked list

  // find alphabetical position
  ListNode* pos = head;
  ListNode* before = NULL;

  // 0 - means need to add new Node to end
  // 1 - means found node with same string word
  // 2 - means need to add node at beginning or in middle
  int operation = 0; 
  while(pos != NULL) { // iterate through Linked List to find right index
    if(pos.getValue() == word) {
      pos.addAppear();
      operation = 1;
      break;
    } else if(word > pos.getValue()) { // keep going down list
      before = pos;
      pos = pos->next;
    } else {
      
      break;
    }
  }

  if(operation == 0) {

  } else if(operation == 2) {
    if(before != NULL) { // need to add new node in middle
        ListNode* newNode = new ListNode(word, before->next);
        before->next = newNode;
    } else { // need to add new node in beginning

    }
  }

  return head;
  

  

}

void ListNode::addAppear(int add) {
  appear += add;
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

  cout << "Enter word to search: ";
  string find;
  cin >> find;

  string line;
  ifstream myfile (fileName);
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
      line = transform(sl.begin(), sl.end(), sl.begin(), ::tolower); // to lower case
      cout << line << '\n';
    }
      myfile.close();
    }
  else { cout << "Unable to open file"; }
  return 0;
}