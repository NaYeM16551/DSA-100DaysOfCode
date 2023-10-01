#include <bits/stdc++.h>
#include "headerFile/tree.h"

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

void levelOrderTraversal(TreeNode *root)
{
  if (!root)
    return;
  queue<TreeNode *> q;
  q.push(root);
  int levelSize = q.size();
  while (!q.empty())
  {
    auto node = q.front();
    q.pop();
    cout << node->data << " ";
    levelSize--;
    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);
    if (!levelSize)
    {
      cout << endl;
      levelSize = q.size();
    }
  }
}

vector<int> reverseLevelOrder(TreeNode *root)
{
  if (!root)
    return {};
  queue<TreeNode *> q;
  q.push(root);
  vector<int> ans;
  int levelSize = q.size();
  while (!q.empty())
  {
    auto node = q.front();
    q.pop();
    ans.push_back(node->data);
    levelSize--;
    if (node->right)
      q.push(node->right);
    if (node->left)
      q.push(node->left);
    if (!levelSize)
    {
      ans.push_back(-1);
      levelSize = q.size();
    }
  }
  ans.pop_back();
  reverse(ans.begin(), ans.end());
  return ans;
}

TreeNode *buildTree(TreeNode *root)
{
  cout << "Enter data :<<";
  int data;
  cin >> data;
  if (data == -1)
    return nullptr;
  root = new TreeNode(data);
  cout << "Enter data for left of " << data << " :";
  root->left = buildTree(root->left);
  cout << "Enter data for right of " << data << " :";
  root->right = buildTree(root->right);
  return root;
}

vector<int> preOrder(TreeNode *root)
{
  if (!root)
    return {};
  stack<TreeNode *> s;
  s.push(root);
  vector<int> preOrder;
  while (!s.empty())
  {
    auto node = s.top();
    preOrder.push_back(node->data);
    s.pop();
    if (node->right)
      s.push(node->right);
    if (node->left)
      s.push(node->left);
  }

  return preOrder;
}

vector<int> inorder(TreeNode *root)
{
  if (!root)
    return {};
  stack<TreeNode *> s;
  vector<int> inorder;
  auto node = root;
  while (true)
  {
    if (node)
    {
      s.push(node);
      node = node->left;
    }
    else
    {
      if (s.empty())
        break;
      else
      {
        node = s.top();
        s.pop();
        inorder.push_back(node->data);
        node = node->right;
      }
    }
  }
  return inorder;
}
vector<int> postorderTraversal(TreeNode *root)
{
  if (!root)
    return {};
  stack<TreeNode *> s1;
  vector<int> ans;
  s1.push(root);
  while (!s1.empty())
  {
    auto node = s1.top();
    ans.push_back(node->data);
    s1.pop();
    if (node->left)
      s1.push(node->left);
    if (node->right)
      s1.push(node->right);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

/* int main()
{
  TreeNode *root = nullptr;
  ifstream fin("input.txt");
  buildTreeFromLevelOrder(root, fin);
  auto ans = preOrder(root);
  for (auto &i : ans)
    cout << i << " ";
  cout << endl;

  return 0;
} */