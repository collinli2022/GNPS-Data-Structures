// Collin Li
// Data Structures
// 05/24/2021
// TreeLab header file    

// Preprocessor directive
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// header guards
#ifndef TREELAB_H
#define TREELAB_H

class TreeNode {
  private:
    string c;
    int freq = 1;
    TreeNode* left;
    TreeNode* right;
  public:
    TreeNode(string cc = "", TreeNode * l = nullptr, TreeNode * r = nullptr) {
        c = cc;
        left = l;
        right = r;
        freq = 1;
    }
    TreeNode* insert(TreeNode* t, string s); // inserts a node containing the character into the tree
    //string display(TreeNode* t, int level);
    string toString(TreeNode* t);
    ~TreeNode() { left = nullptr; right = nullptr; delete left; delete right; }
};

TreeNode* TreeNode::insert(TreeNode* t, string s) {
  if (t==NULL) { return new TreeNode(s); } // Insert the first node, if root is NULL.
  else if (c == "") { t->c = s; }
  else if (s.compare(t->c) == 0) { t->freq += 1; }
  else if (s.compare(t->c) > 0) { t->right = insert(t->right, s); } // Insert right node data, if the 'value' is greater than root's data
  else { t->left = insert(t->left, s); } // Insert left node data, if the 'value' is less than or equal to root's data

  return t;
}

/*
// Print nodes at a given level (visual display)
string TreeNode::display(TreeNode* t, int level) {
    string str = "";
    if (t == NULL) { return ""; } // Base case
    str += display(t->right, level+1); // Process right child first 
    str += "\n";
    for (int i = 0; i < level*5; i++) { str += " "; }
    str += t->c;
    str += "\n"; 
    str += display(t->left, level+1); // Process left child 
    return str;
}
*/

string TreeNode::toString(TreeNode* t) {
    string s = "";
    if (t==NULL) { return ""; }
    s += toString(t->left); // then recur on left sutree
    s +=  t->c + ": " + to_string(t->freq) + "\n"; // first print data of node
    s += toString(t->right); // now recur on right subtree
    return s;
}

#endif