// Collin Li
// Data Structures
// 04/28/2021
// TreeLab header file    

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;

// header guards
#ifndef TREELAB_H
#define TREELAB_H

class TreeNode {
  private:
    char c;
    TreeNode* left;
    TreeNode* right;
  public:
    TreeNode(char cc) { c = cc; }
    //this class must contain the following methods:
    TreeNode* buildTree(string s); // takes a string parameter and builds a BST where each letter is a node
    TreeNode* insert(TreeNode* t, char s); // inserts a node containing the character into the tree
    string display(TreeNode* t, int level);
    string preorderTraverse(TreeNode* t);
    string inorderTraverse(TreeNode* t);
    string postorderTraverse(TreeNode* t);
    int countNodes(TreeNode* t);
    int countLeaves(TreeNode* t);
    int countGrandParents(TreeNode* t);
    int countOnlyChildren(TreeNode* t);
    int height(TreeNode* t); // returns the max of the heights to the left and the heights to the right
    int longestPath(TreeNode* t); // return the max of the sum of the heights to the left and the heights to the right
    char min(TreeNode* t);
    char max(TreeNode* t);
    string displayCurrentLevel(TreeNode* t, int level);
    string displayLevelOrder(TreeNode* t);
    char getValue() { return c; }
    ~TreeNode() { left = nullptr; right = nullptr; delete left; delete right; }
    //you may have TreeNode objects or TreeNode pointers as parameters/returns based upon how you set up your code
};

TreeNode* TreeNode::buildTree(string s) {
  TreeNode* returnTree = new TreeNode(' ');
  for(int i = 0; i < s.length(); i++) {
    if(i==0) { returnTree->c = s[0]; }
    else { returnTree = insert(returnTree, s[i]); }
  }
  return returnTree;
}

TreeNode* TreeNode::insert(TreeNode* t, char s) {
  if (t==NULL) { return new TreeNode(s); } // Insert the first node, if root is NULL.
  if (s > t->c) { t->right = insert(t->right, s); } // Insert right node data, if the 'value' is greater than root's data
  else { t->left = insert(t->left, s); } // Insert left node data, if the 'value' is less than or equal to root's data

  return t;
}

/* Print nodes at a given level */
string TreeNode::display(TreeNode* t, int level) {
    string s = "";
    if (t == NULL) {return ""; }
    if (level == 1) { s += string(1, t->c); }
    else if (level > 1) {
        display(t->left, level-1);
        display(t->right, level-1);
    }
    return s;
}

string TreeNode::preorderTraverse(TreeNode* t) {
    string s = "";
    if (t==NULL) { return ""; }
    s += t->c; // first print data of node
    s += inorderTraverse(t->left); // then recur on left sutree
    s += inorderTraverse(t->right); // now recur on right subtree
    return s;
}

string TreeNode::inorderTraverse(TreeNode* t) {
  string s = "";
  if (t==NULL) { return ""; }
  s += inorderTraverse(t->left); // first recur on left child
  s += t->c; // then print the data of node
  s += inorderTraverse(t->right); // now recur on right child
  return s;
}

string TreeNode::postorderTraverse(TreeNode* t) {
    string s = "";
    if (t==NULL) { return ""; }
    s += inorderTraverse(t->left); // first recur on left child
    s += inorderTraverse(t->right); // then recur on right child
    s += t->c; // now deal with the node
    return s;
}

int TreeNode::countNodes(TreeNode* t) {
    int sum = 1;
    if (t==NULL) { return 0; }
    sum += countNodes(t->left);
    sum += countNodes(t->right);
    return sum;
}

int TreeNode::countLeaves(TreeNode* t) {
    int sum = 0;
    if (t==NULL) { return 0; }
    if(t->left == NULL && t->right == NULL) { // A leaf is a node that has no children.
        return 1;
    }
    sum += countLeaves(t->left);
    sum += countLeaves(t->right);
    return sum;
}

#endif

int main() {
  //the tree contains the letters of the string, starting at position 1
  string s = "XCOMPUTERSCIENCE";
  //string s = "XGNSHighSchool"; 
  //string s = "XAComputerScienceTreeHasItsRootAtTheTop";
  //string s = "XA";   
  //string s = "XAF";  
  //string s = "XAFP";  
  //string s = "XDFZM";   
  
  TreeNode* root = nullptr;
  cout << "start" << endl;
  root = root->buildTree(s);
  cout << "1" << endl;
  cout << root->display(root, 0) << endl;

  cout << "\nPreorder: " << root->preorderTraverse(root) << endl;
  cout << "\nInorder: " << root->inorderTraverse(root) << endl;
  cout << "\nPostorder: " << root->postorderTraverse(root) << endl;

  cout << "\n\nNodes = " << root->countNodes(root) << endl;
  cout << "Leaves = " << root->countLeaves(root) << endl;
  /*
  cout << "Only children = " << root->countOnlyChildren(root) << endl;
  cout << "Grandparents = " << root->countGrandParents(root) << endl;

  cout << "\nHeight of tree = " << root->height(root) << endl;
  cout << "Longest path = " << root->longestPath(root) << endl;
  cout << "Min = " << root->min(root) << endl;
  cout << "Max = " << root->max(root) << endl;	

  cout << "\nBy Level: " << root->displayLevelOrder(root) << endl;
    */

  return 0;
}
