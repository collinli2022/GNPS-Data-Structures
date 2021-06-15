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
    // constructor
    WordNode(); 
    
    // build tre
    WordNode* buildTree(ifstream &file, int &count);
    void insert(WordNode* w, string s);
    void traverse(string prefix, WordNode* w, ofstream &file);
    int countNodes(WordNode* w);
    // other methods as desired
    void display(struct TrieNode* root, char str[], int level) {
        // If node is leaf node, it indicates end
        // of string, so a null character is added
        // and string is displayed
        if (isLeafNode(root)) {
            str[level] = '\0';
            cout << str << endl;
        }
      
        int i;
        for (i = 0; i < alpha_size; i++)  {
            // if NON NULL child is found
            // add parent key to str and
            // call the display function recursively
            // for child node
            if (root->children[i]) {
                str[level] = i + 'a';
                display(root->children[i], str, level + 1);
            }
        }
    }
};

WordNode* WordNode::buildTree(ifstream &file, int &count) {
  if (file.is_open()) { // open file
    while ( getline (file, line) ) { // get lines
      transform(line.begin(), line.end(), line.begin(), ::tolower); // to lower case (even though the assignment says only lower case... backup)
      
      istringstream ss(line); // Used to split string around spaces.
      string word; // for storing each word
      while (ss >> word) { this->insert(word); count += 1; } // loop through all words in line
    }
    file.close();
    } else { cout << "Unable to open file"; }
}

void WordNode::insert(WordNode* w, string s) {
  WordNode* temp = w;
  for (int i = 0; i < s.length(); i++) { // each char is a layer
      int index = s[i] - 'a'; // only lowercase letter
      if (!temp->children[index]) { temp->children[index] = getNode(); } // char does not exist
      else { temp = temp->children[index]; }
  }

  // mark last node as leaf
  temp->isEndOfWord = true;
}

void WordTree::traverse(string prefix, WordNode* w, ofstream &file) {

}

int main() {
  WordNode* root = new WordNode();
  // Big loop:
  // read a word
  // count the total number of letters
  // for each letter in the word
  // get the position of the letter in the children array
  // if the letter isn&#39;t there
  // add a node
  // get the next level
  // add the node for end-of-word marker
  // Print the statistics: total letters, total nodes, %
  // Output the list in result.txt in alphabetical order
  return 0;
}