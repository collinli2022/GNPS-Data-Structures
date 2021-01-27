// Collin Li
// Data Structures
// 01/27/2020
// MiniProject WordCount 

#include <iostream>
#include <fstream>
using namespace std;

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

  ASK MRS.ZINN can i first search for the word without linked list then store into linked list

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