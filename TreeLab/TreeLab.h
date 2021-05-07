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
    ~TreeNode() { left = nullptr; right = nullptr; delete left; delete right; }
    //you may have TreeNode objects or TreeNode pointers as parameters/returns based upon how you set up your code
};

TreeNode* TreeNode::buildTree(string s) {
  c = ''; left = nullptr; right = nullptr;
  for(int i = 0; i < s.length(); i++) {
    if(i==0) { c = s[i] }
    else {
      this->insert(this, s[i])
    }
  }
}

TreeNode* TreeNode::insert(TreeNode* t, char s) {
  if (t==NULL) { return new BST(value); } // Insert the first node, if root is NULL.
  if (value > t->c) { t->right = Insert(root->right, value); } // Insert right node data, if the 'value' is greater than root's data
  else { root->left = Insert(root->left, value); } // Insert right node data, if the 'value' is less than or equal to root's data

  return root;
}

#endif