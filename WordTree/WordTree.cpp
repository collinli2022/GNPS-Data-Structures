// Collin Li
// Data Structures
// 05/27/2020
// WordTree Project

#include <iostream>
#include <fstream>
#include<bits/stdc++.h> 
using namespace std;

class WordNode {
  private:
    WordNode* children[26];
    bool endOfWord;
  public:
    WordNode() { endOfWord = false; } // constructor
    
    WordNode* buildTree(ifstream &file, int &count);
    void insert(WordNode* w, string s);
    void traverse(string prefix, WordNode* w, ofstream &file);
    int countNodes(WordNode* w);
};

WordNode* WordNode::buildTree(ifstream &file, int &count) {
    WordNode* output = new WordNode (); // head of tree
    string s; // temp
    while(file>>s) { output->insert(output, s); count += s.length(); } // count each insert
    return output;
}

void WordNode::insert(WordNode* w, string s) {
  for(int i = 0; i < s.length(); i++) { // loop through char in string
    if(w->children[s[i]-'a'] == NULL) { w->children[s[i]-'a'] = new WordNode(); } // if that char does not exist, add new one
    w = w->children[s[i]-'a']; 
  }
  w->endOfWord = true;
}

void WordNode::traverse(string prefix, WordNode* w, ofstream &file) {
    for(int i = 0; i < 26; i++) { // goes through each branch
        if(w->children[i] != NULL) { // make sure branch is NULL
            string combined = prefix+char(i + 'a'); // prefix + current letter
            if(w->children[i]->endOfWord == true) { file << combined << endl; } // end of word so add to output file
            w->traverse(combined, w->children[i], file); // recursion
        }
    }
}

int WordNode::countNodes(WordNode* w) {
  int totalNodes = 1; // include itself
  for (int i = 0; i < 26; i++)  { // other branches
    if (w->children[i] != NULL) {
      totalNodes += countNodes(w->children[i]); // add other nodes recursivly
    }
  }
  return totalNodes;
}

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