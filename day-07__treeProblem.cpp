#include <bits/stdc++.h>

#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";
#define trav(i, v) for (auto &i : v)
#include "headerFile/tree.h"

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;
bool rootToNodePath(TreeNode *root, int node, vector<int> &path)
{
    if (!root)
        return false;
    path.push_back(root->data);
    if (root->data == node)
        return true;
    if (rootToNodePath(root->left, node, path) || rootToNodePath(root->right, node, path))
        return true;
    path.pop_back();
    return false;
}
TreeNode *findNode(TreeNode *root, int target)
{
    if (!root)
        return nullptr;
    if (root->data == target)
        return root;
    auto left = findNode(root->left, target);
    auto right = findNode(root->right, target);
    return (left != nullptr) ? left : right;
}

int timeTaken(TreeNode *targetNode, unordered_map<TreeNode *, bool> &visited, unordered_map<TreeNode *, TreeNode *> &parent)
{
    int time = 0;
    queue<TreeNode *> q;
    q.push(targetNode);
    int levelSize = q.size();
    watch(levelSize);
    while (!q.empty())
    {
        auto node = q.front();
        visited[node] = true;
        q.pop();
        levelSize--;
        if (node->left && !visited[node->left])
            q.push(node->left);
        if (node->right && !visited[node->right])
            q.push(node->right);
        auto parentNode = parent[node];
        if (parentNode && !visited[parentNode])
            q.push(parentNode);
        if (!levelSize && !q.empty())
        {
            time++;
            levelSize = q.size();
        }
    }
    return time;
}

int minTime(TreeNode *root, int target)
{
    // Your code goes here
    if (!root)
        return 0;
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(root);
    unordered_map<TreeNode *, TreeNode *> parent;
    parent[root] = nullptr;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        visited[node] = false;
        if (node->left)
        {
            parent[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
    watch("After first while");
    auto node = findNode(root, target);
    if (!node)
        return 0;
    watch("After Node finding"); 
    watch(node->data);  
    int time = timeTaken(node, visited, parent);
    return time;
}
int main()
{
    TreeNode *root = nullptr;
    ifstream fin("input.txt");
    buildTreeFromLevelOrder(root, fin);
    cout<<minTime(root,8);
    return 0;
}