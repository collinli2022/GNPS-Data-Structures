// Collin Li
// Data Structures
// 04/28/2021
// TreeLab header file    

// Preprocessor directive
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
    TreeNode(char cc = 0, TreeNode * l = nullptr, TreeNode * r = nullptr) {
        c = cc;
        left = l;
        right = r;
    }
    // this class must contain the following methods:
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
  TreeNode* returnTree = new TreeNode(' ');
  for(int i = 1; i < s.length(); i++) {
    if(i==1) { returnTree->c = s[1]; }
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

string TreeNode::preorderTraverse(TreeNode* t) {
    string s = "";
    if (t==NULL) { return ""; }
    s += t->c; // first print data of node
    s += preorderTraverse(t->left); // then recur on left sutree
    s += preorderTraverse(t->right); // now recur on right subtree
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
    s += postorderTraverse(t->left); // first recur on left child
    s += postorderTraverse(t->right); // then recur on right child
    s += t->c; // now deal with the node
    return s;
}

int TreeNode::countNodes(TreeNode* t) {
    int sum = 1;
    if (t==NULL) { return 0; }
    sum += countNodes(t->left); // count nodes to left
    sum += countNodes(t->right); // count nodes to right
    return sum;
}

int TreeNode::countLeaves(TreeNode* t) {
    int sum = 0;
    if (t==NULL) { return 0; }
    if (t->left == NULL && t->right == NULL) { // A leaf is a node that has no children.
        return 1;
    }
    sum += countLeaves(t->left);
    sum += countLeaves(t->right);
    return sum;
}

int TreeNode::countGrandParents(TreeNode* t) {
    int total = 0;
    if (t == NULL) { return 0; }
    if (t->left != NULL && t->right != NULL) {
        if (t->left->left != NULL
            || t->left->right != NULL
            || t->right->left != NULL
            || t->right->right != NULL) { // Check for grandchildren
            total += 1;
        }
    } else if (t->left != NULL) { // Check grandchildren for only left side 
        if (t->left->left != NULL
            || t->left->right != NULL) {
            total += 1;
        }
    } else if (t->right != NULL) { // Check grandchildren for only right side
        if (t->right->left != NULL
            || t->right->right != NULL) {
            total += 1;
        }
    }
    // Recursive call on left and
    // right subtree
    total += countGrandParents(t->left);
    total += countGrandParents(t->right);
    return total;
}

int TreeNode::countOnlyChildren(TreeNode* t) {
    int total = 0;
    if (t==NULL || (t->left == NULL && t->right == NULL)) { return 0; }
    if (t->left == NULL || t->right == NULL) { // check if an only child
        if(t->left == NULL) {
            total += 1;
            total += countOnlyChildren(t->right); // left is null so go right
        } else {
            total += 1;
            total += countOnlyChildren(t->left); // right is null so go left
        }
    } else {
        total += countOnlyChildren(t->right);
        total += countOnlyChildren(t->left);
    }
    return total;
}

int TreeNode::height(TreeNode* t) { // returns the max of the heights to the left and the heights to the right
  if (t == NULL) { return 0; }
  int lDepth = height(t->left);
  int rDepth = height(t->right);
  if (lDepth > rDepth) { return(lDepth + 1); } // return the larger one
  else { return (rDepth + 1); }
}

int TreeNode::longestPath(TreeNode* t) { // return the max of the sum of the heights to the left and the heights to the right
  int longestPath = 0;
  longestPath += t->height(t->left); // left height
  longestPath += t->height(t->right); // right height
  return longestPath;
}

char TreeNode::min(TreeNode* t) {
  TreeNode* current = t;
  while (current->left != NULL) { current = current->left; } // loop down to find the leftmost leaf
  return (current->c); 
}

char TreeNode::max(TreeNode* t) {
  TreeNode* current = t;
  while (current->right != NULL) { current = current->right; } // loop down to find the rightmost leaf
  return (current->c);
}

string TreeNode::displayCurrentLevel(TreeNode* t, int level) {
    string s = "";
    if (t == NULL) { return ""; }
    if (level == 0) { s += t->c; }
    else if (level >= 1) {
        s += displayCurrentLevel(t->left, level-1);
        s += displayCurrentLevel(t->right, level-1);
    }
    return s;
}

string TreeNode::displayLevelOrder(TreeNode* t) {
    string str = "";
    for (int i = 0; i < t->height(t); i++) { str += t->displayCurrentLevel(t, i); }
    return str;
}

#endif