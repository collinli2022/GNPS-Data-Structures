// Name: Collin Li
// Date: 4/28/2021

//includes
#include "TreeLab.h" //put your class inside TreeLab.h

class TreeNode {
	//this class must contain the following methods:
	//TreeNode* buildTree(String s) takes a string parameter and builds a BST where each letter is a node
	//TreeNode* insert(TreeNode* t, char s) inserts a node containing the character into the tree
	//string display(TreeNode* t, int level)
	//string preorderTraverse(TreeNode* t)
	//string inorderTraverse(TreeNode* t)
	//string postorderTraverse(TreeNode* t)
	//int countNodes(TreeNode* t)
	//int countLeaves(TreeNode* t)
	//int countGrandParents(TreeNode* t)
	//int countOnlyChildren(TreeNode* t)
	//int height(TreeNode* t) returns the max of the heights to the left and the heights to the right ;
	//int longestPath(TreeNode* t) return the max of the sum of the heights to the left and the heights to the right
	//char min(TreeNode* t)
	//char max(TreeNode* t)
	//string displayCurrentLevel(TreeNode* t, int level)
	//string displayLevelOrder(TreeNode* t) 
	
	//this class must contain the character representing the current letter as well as pointers to the left and right
	//children
	//you may have TreeNode objects or TreeNode pointers as parameters/returns based upon how you set up your code
};  

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
  root = root->buildTree(s);
  cout << display(root, 0) << endl;

  cout << "\nPreorder: " << root->preorderTraverse(root) << endl;
  cout << "\nInorder: " << root->inorderTraverse(root) << endl;
  cout << "\nPostorder: " << root->postorderTraverse(root) << endl;

  cout << "\n\nNodes = " << root->countNodes(root) << endl;
  cout << "Leaves = " << root->countLeaves(root) << endl;
  cout << "Only children = " << root->countOnlyChildren(root) << endl;
  cout << "Grandparents = " << root->countGrandParents(root) << endl;

  cout << "\nHeight of tree = " << root->height(root) << endl;
  cout << "Longest path = " << root->longestPath(root) << endl;
  cout << "Min = " << root->min(root) << endl;
  cout << "Max = " << root->max(root) << endl;	

  cout << "\nBy Level: " << root->displayLevelOrder(root) << endl;

  return 0;
}