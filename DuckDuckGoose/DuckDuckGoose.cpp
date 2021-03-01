// Collin Li
// Data Structures
// 03/01/2021
// DuckDuckGoose MiniProject 

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;

class ListNode {
  private:
    string value;
    ListNode* previous;
    ListNode* next;
    int length(ListNode* head); // helper method to get length of LinkedList
  public:
    ListNode(string a="", ListNode* b=NULL, ListNode* n=NULL); // constructor

    string simulate(ListNode* head); // returns the winner name

    //inserts a Node into LinkedList
    ListNode* add(ListNode* head, string y, int position=0);

    //deletes a node from LinkedList
    ListNode* remove(ListNode* head, int position=0);
    ListNode* remove(ListNode* head, ListNode* node);

    // Getters
    string getValue() { return value; }
    ListNode* getNext() { return next; }
    ListNode* getPrevious() { return previous; }

    ~ListNode() { delete next; } // deconstructor that deletes pointer
}

ListNode::ListNode(string a, ListNode* b, ListNode* n) { // sets string and pointers
  value = a;
  previous = b; 
  next = n;
}

string ListNode::simulate(ListNode* head) {
  int cycleLength = 3;
  int participants = head->length();
  while(participants > 1) { // keep playing till winner

    for(int i = 0; i < cycleLength; i++) { // Duck (+1) Duck (+1) Goose (*)
      head = head->next;
    }

    // remove current head node
    ListNode* next = head->next;
    head->previous->next = head->next; // previous node's next is head's next
    head->next->previous = head->previous; // next node's previous is head's previous
    head = nullptr;
    head = next;
    delete next;

  }
  return head->value; // should just be one remaining
}

/*
Write a program called DuckDuckGoose that first prompts the user for the name of a file and then performs the DuckDuckGoose algorithm from Intro to Programming. The txt file will contain a series of runs of the program. The first line for each run is the number of participants and the second line is the cycle. The cycle number does not need to be less than the number of participants, but both will be positive values. Your program must output the trial number followed by a colon and a single space and then the position of the trial winner, one trial per line, in a new text file called "result.txt" that is created by your program. Your program MUST use a circular linked list to run each trial. Standard rules apply for formatting and usability. 4 points for documentation, 4 points for user-friendliness, 24 points for the required functionality (file read, linked list, file write, correct result for each trial).
*/

int main() {

  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string fileName;
  cin >> fileName;

  ListNode* words = NULL; // will represent head of linked list containing words

  string line;
  ifstream myfile (fileName);
  if (myfile.is_open()) { // open file
    while ( getline (myfile, line) ) { // get lines
      
      istringstream ss(line); // Used to split string around spaces.
 
      string word; // for storing each word
     
      while (ss >> word) { // loop through all words in line

      }
    }
    myfile.close();
  } else { cout << "Unable to open file"; }

  return 0;
}