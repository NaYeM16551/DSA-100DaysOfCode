# pragma once 

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int data)
  {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};


int height(const TreeNode *root);
bool isBalanced(const TreeNode *root);
bool isBstCheck(const TreeNode *root, int minValue, int maxValue);
bool isBST(const TreeNode *root);
bool isPerfectCheck(const TreeNode *root, int depth, int level = 0);
bool isPerfect(const TreeNode *root);
int countNodes(const TreeNode *root);
bool isCompleteCheck(const TreeNode *root, int numberOfNodes, int index = 0);
bool isComplete(TreeNode *root);
bool isFullBinaryTree(const TreeNode *root);
bool symmetricHelp(const TreeNode *left, const TreeNode *right);
bool isSymmetric(const TreeNode *root);
void buildTreeFromLevelOrder(TreeNode *&root, ifstream &fin);
