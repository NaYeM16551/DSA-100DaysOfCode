#include <bits/stdc++.h>

#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";
#define trav(i, v) for (auto &i : v)
#include "headerFile/tree.h"

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

int childrenSumProperty(TreeNode*&root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->data;
    int sum = 0;
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;
    if (root->left && sum < root->data)
        root->left->data = sum;
    if (root->right && sum < root->data)
        root->right->data = sum;
    if (sum > root->data)
        root->data = sum;
    int left = childrenSumProperty(root->left);
    int right = childrenSumProperty(root->right);
    return root->data = left + right;
}

vector<int> KDistanceNodes(TreeNode*root, int target, int k)
{
    // return the sorted vector of all nodes at k dist
    if (!root)
        return {};
    unordered_map<TreeNode*, TreeNode*> parent;
    queue<TreeNode*> q;
    q.push(root);
    parent[root] = nullptr;
    TreeNode*targetNode = nullptr;
    unordered_map<TreeNode*, bool> visited;

    while (!q.empty())
    {
        auto node = q.front();
        visited[node] = false;
        q.pop();
        if (node->data == target)
            targetNode = node;
        if (node->left)
        {
            q.push(node->left);
            parent[node->left] = node;
        }
        if (node->right)
        {
            q.push(node->right);
            parent[node->right] = node;
        }
    }

    q.push(targetNode);

    int i = k;
    while (!q.empty() && i > 0)
    {
        int size = q.size();
        for (int j = 0; j < size; ++j)
        {
            auto node = q.front();
            visited[node] = true;
            q.pop();
            if (node->left && !visited[node->left])
                q.push(node->left);
            if (node->right && !visited[node->right])
                q.push(node->right);
            if (parent[node] && !visited[parent[node]])
                q.push(parent[node]);
        }

        i--;
    }

    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
vector<int> serialize(TreeNode*root)
{
    // Your code here
    if (!root)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (node == nullptr)
        {
            ans.push_back(-1);
            continue;
        }
        ans.push_back(node->data);
        if (node->left)
            q.push(node->left);
        else
            q.push(nullptr);
        if (node->right)
            q.push(node->right);
        else
            q.push(nullptr);
    }
    return ans;
}
TreeNode*deSerialize(vector<int> &v)
{
    // Your code here
    if (v.empty())
        return nullptr;
    queue<TreeNode*> q;
    TreeNode*root = new TreeNode(v[0]);
    q.push(root);

    for (int i = 1; i < v.size(); ++i)
    {
        int size = q.size();
        for (int j = 0; j < size; ++j)
        {
            auto node = q.front();
            q.pop();
            int data = v[i++];
            if (data == -1)
                node->left = nullptr;
            else
            {
                auto leftNode = new TreeNode(data);
                node->left = leftNode;
                q.push(leftNode);
            }
            data = v[i];
            if (data == -1)
                node->right = nullptr;
            else
            {
                auto rightNode = new TreeNode(data);
                node->right = rightNode;
                q.push(rightNode);
            }
        }
    }
    return root;
}

int main()
{
    TreeNode *root = nullptr;
    ifstream fin("input.txt");
    buildTreeFromLevelOrder(root, fin);
    auto ans = serialize(root);
    show(ans);
    TreeNode *root2=deSerialize(ans);
    levelOrderTraversal(root2);
    
}