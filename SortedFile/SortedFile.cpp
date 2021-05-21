// Collin Li
// Data Structures
// 05/17/2021
// TreeLab header file    

// Preprocessor directive

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "TreeLab.h"
using namespace std;

/*
Write a program that reads in a text file (input.txt), stores all of the words in a binary search tree, and outputs the word followed by a colon and a space and then the number of times it appears, one per line (result.txt). "He" and "he" are different words. Order them in proper ASCII arrangement. File will contain no punctuation. Standard rules apply.
*/

int main() {
  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string inputName;
  cin >> inputName;

  TreeNode* sorter = new TreeNode(); // used to solve

  string line;
  ifstream fileInput(inputName); // Creates an input stream
  ofstream fileOutput;  
  
  int trialIndex = 0; // count trial number
  if (fileInput.is_open()) { // open file
    fileOutput.open("result.txt");
    while ( getline (fileInput, line) ) { // get lines
      istringstream ss(line);
      string word; // for storing each word
      while (ss >> word) { sorter->insert(sorter, word); } // insert words
      trialIndex += 1;
    }
    //cout << sorter->display(sorter, 0) << endl; // debug
    fileOutput << sorter->toString(sorter); // output into result file
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}