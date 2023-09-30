#include <bits/stdc++.h>
#include "headerFile/tree.h"

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

#define Max(x, y, z) max(x, max(y, z))
#define Min(x, y, z) min(x, min(y, z))
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)

using namespace std;
// Definition for a binary tree node
int depth(const TreeNode *root)
{
  if (root == nullptr)
    return -1;
  return 1 + depth(root->left);
}
int height(const TreeNode *root)
{
  if (!root)
    return 0;
  int lh = height(root->left);
  int rh = height(root->right);
  return max(lh, rh) + 1;
}

bool isBalanced(const TreeNode *root)
{
  if (!root)
    return true;

  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    return true;

  return false;
}
bool isBstCheck(const TreeNode *root, int minValue, int maxValue)
{
  if (!root)
  {
    return true; // An empty tree is a BST
  }

  if (root->data < minValue || root->data > maxValue)
  {
    return false; // Node's dataue is outside the dataid range
  }

  // Check the left and right subtrees
  return isBstCheck(root->left, minValue, root->data - 1) &&
         isBstCheck(root->right, root->data + 1, maxValue);
}

bool isBST(const TreeNode *root)
{
  return isBstCheck(root, INT_MIN, INT_MAX);
}
bool isPerfectCheck(const TreeNode *root, int depth, int level)
{

  if (root == nullptr)
    return true;
  if (root->left == nullptr && root->right == nullptr)
  {
    return depth == level;
  }

  else if (root->right == nullptr || root->left == nullptr)
  {
    return false;
  }

  return isPerfectCheck(root->left, depth, level + 1) && isPerfectCheck(root->right, depth, level + 1);
}

bool isPerfect(const TreeNode *root)
{
  int d = depth(root);
  return isPerfectCheck(root, d);
}
int countNodes(const TreeNode *root)
{
  if (root == nullptr)
    return 0;
  return countNodes(root->left) + countNodes(root->right) + 1;
}
bool isCompleteCheck(const TreeNode *root, int numberOfNodes, int index)
{
  if (root == nullptr)
    return true;
  if (index >= numberOfNodes)
    return false;
  return isCompleteCheck(root->left, numberOfNodes, 2 * index + 1) && isCompleteCheck(root->right, numberOfNodes, 2 * index + 2);
}
bool isComplete(TreeNode *root)
{
  int numberOfNodes = countNodes(root);
  cout << "Number of nodes " << numberOfNodes << endl;
  return isCompleteCheck(root, numberOfNodes);
}
bool isFullBinaryTree(const TreeNode *root)
{
  if (root == nullptr)
    return true;
  if (!root->left && !root->right)
    return true;
  if (root->right && root->left)
    return isFullBinaryTree(root->right) && isFullBinaryTree(root->left);
  return false;
}

bool isFull(const TreeNode *root)
{
  if (!root)
    return true;
  queue<TreeNode *> q;
  q.push(const_cast<TreeNode*>(root));
  while (!q.empty())
  {
    auto node = q.front();
    q.pop();
    if (node->left && !node->right)
      return false;
    if (node->right && !node->left)
      return false;
    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);
  }
  return true;
}
bool symmetricHelp(const TreeNode *left, const TreeNode *right)
{
  if (!left || !right)
    return left == right;
  if (left->data != right->data)
    return false;
  return symmetricHelp(left->left, right->right) && symmetricHelp(left->right, right->left);
}
bool isSymmetric(const TreeNode *root)
{
  return symmetricHelp(root->left, root->right);
}
void buildTreeFromLevelOrder(TreeNode *&root, ifstream &fin)
{
  queue<TreeNode *> q;
  // cout << "Enter data for the root node : ";
  int data;
  fin >> data;
  if (data != -1)
  {
    root = new TreeNode(data);
    q.push(root);
  }

  while (!q.empty())
  {
    auto node = q.front();
    data = node->data;
    q.pop();
    // cout << " Enter leftNode data for  " << data << " :";
    int leftNodeData;
    fin >> leftNodeData;
    if (leftNodeData != -1)
    {
      node->left = new TreeNode(leftNodeData);
      q.push(node->left);
    }
    // cout << "Enter rightNodeData for " << data << " :";
    int rightNodeData;
    fin >> rightNodeData;
    if (rightNodeData != -1)
    {
      node->right = new TreeNode(rightNodeData);
      q.push(node->right);
    }
  }
}

/* int32_t main()
{
  IOS;
  ifstream fin("input.txt");

  TreeNode *root = nullptr;
  buildTreeFromLevelOrder(root, fin);
  bool ans = isPerfect(root);
  if (ans)
    cout << "Full Binary Tree" << endl;
  else
    cout << "Not Full Binary Tree" << endl;
} */