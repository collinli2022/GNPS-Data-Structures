// Collin Li
// Data Structures
// 05/27/2020
// WordTree Project

#include <iostream>
#include <fstream>
#include "WordTree.h"
using namespace std;


int main() {
  ifstream ifs("input.txt"); // Creates input stream
  ofstream ofs("result.txt"); // Creates output stream
  
  int list = 0; // represents list total
  WordNode* root = new WordNode();
  root = root->buildTree(ifs, list); // build tree

  int tree = root->countNodes(root); // represents tree total
  float savings = (1.0 - (float) tree / (float) list) * (100); // calculate savings
  
  // Print the statistics: total letters, total nodes, %
  cout << "List Total: " << list << endl << "Tree Total: " << tree << endl << "Savings Total: " << savings << endl;

  // Output the list in result.txt in alphabetical order
  root->traverse("", root, ofs);
  return 0;
}