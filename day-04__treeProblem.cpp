#include <bits/stdc++.h>
#include "headerFile/tree.h"

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;
vector<int> zigZagTraversal(TreeNode *root)
{
    // Code here
    if (!root)
        return {};
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    bool isLeft = true;

    while (!q.empty())
    {
        int lvlSize = q.size();
        vector<int> res(lvlSize);
        for (int i = 0; i < lvlSize; ++i)
        {
            auto node = q.front();
            q.pop();
            int index = isLeft ? i : lvlSize - i - 1;
            res[index] = node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        isLeft = !isLeft;
        for (auto &i : res)
            ans.push_back(i);
    }
    return ans;
}
void leaf(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        ans.push_back(root->data);
    leaf(root->left, ans);
    leaf(root->right, ans);
}
void leftNode(TreeNode *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;
    ans.push_back(root->data);
    if (root->left)
        leftNode(root->left, ans);
    else
        leftNode(root->right, ans);
}
void rightNode(TreeNode *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;

    if (root->right)
        rightNode(root->right, ans);
    else
        rightNode(root->left, ans);
    ans.push_back(root->data);
}

vector<int> boundary(TreeNode *root)
{
    // Your code here
    if (!root)
        return {};
    vector<int> ans;
    ans.push_back(root->data);
    leftNode(root->left, ans);
    leaf(root->left, ans);
    leaf(root->right, ans);
    rightNode(root->right, ans);
    return ans;
}

/* int main()
{
    vector<int> pre, in, post;
    TreeNode *root = nullptr;
    ifstream fin("input.txt");
    buildTreeFromLevelOrder(root, fin);
    levelOrderTraversal(root);
    cout << endl;

    return 0;
} */