#include <bits/stdc++.h>
#include "headerFile/tree.h"

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

void preInPostTraversal(TreeNode *root, vector<int> &pre, vector<int> &post, vector<int> &in)
{
    if (!root)
        return;
    stack<pair<TreeNode *, int>> s;
    s.push({root, 1});
    while (!s.empty())
    {
        auto it = s.top();
        s.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->left)
                s.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->right)
                s.push({it.first->right, 1});
        }
        else
            post.push_back(it.first->data);
    }
    return;
}

// Function to return the diameter of a Binary Tree.
int diameteer(TreeNode *root)
{
    // Your code here
    if (!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int d = lh + rh + 1;
    return max({d, diameteer(root->left), diameteer(root->right)});
}

pair<int, int> fastDiameter(TreeNode *root)
{
    if (!root)
        return {0, 0};
    auto leftDiameter_and_leftHeight = fastDiameter(root->left);
    auto rightDiameter_and_rightHeight = fastDiameter(root->right);
    int lh = leftDiameter_and_leftHeight.second;
    int rh = rightDiameter_and_rightHeight.second;
    int d = max(lh, rh) + 1;
    return {max({lh + rh + 1, leftDiameter_and_leftHeight.first, rightDiameter_and_rightHeight.first}), d};
}
int isBalancedHelp(TreeNode *root)
{
    // Just call this function,if it returns -1 then not balanced
    if (root == NULL)
        return 0;

    int leftH = height(root->left);

    int rightH = height(root->right);

    if (leftH == -1 or rightH == -1)
        return -1;

    if (abs(leftH - rightH) <= 1)
        return max(leftH, rightH) + 1;
    else
        return -1;
}

pair<bool, int> isBalancedFast(TreeNode *root)
{
    if (!root)
        return {true, 0};
    auto leftBalanced_and_leftHeight = isBalancedFast(root->left);
    auto rightBalanced_and_rightHeight = isBalancedFast(root->right);
    auto leftBalanced = leftBalanced_and_leftHeight.first;
    auto rightBalanced = rightBalanced_and_rightHeight.first;
    auto heightDiff = abs(rightBalanced_and_rightHeight.second - leftBalanced_and_leftHeight.second);
    auto isBalanced = leftBalanced && rightBalanced && (heightDiff <= 1);
    int height = max(rightBalanced_and_rightHeight.second, leftBalanced_and_leftHeight.second) + 1;
    return {isBalanced, height};
}

pair<bool, int> isSumTreeFast(TreeNode *root, int rootData = 0)
{
    if (!root)
        return {true, 0};
    if (!root->left && !root->right)
        return {true, root->data};
    auto leftSubtreeSum_and_isSum = isSumTreeFast(root->left, root->data);
    auto rightSubtreeSum_and_isSum = isSumTreeFast(root->right, root->data);
    auto IsLeftSumTree = leftSubtreeSum_and_isSum.first;
    auto IsRightSumTree = rightSubtreeSum_and_isSum.first;
    auto left_and_right_sum = leftSubtreeSum_and_isSum.second + rightSubtreeSum_and_isSum.second;
    pair<bool, int> p;
    if (IsLeftSumTree && IsRightSumTree && root->data ==left_and_right_sum)
        p.first = true;
    else
        p.first = false;
    p.second = left_and_right_sum + root->data;
    return p;
}
int main()
{
    vector<int> pre, in, post;
    TreeNode *root = nullptr;
    ifstream fin("input.txt");
    buildTreeFromLevelOrder(root, fin);
    auto p = isSumTreeFast(root);
    cout << boolalpha << p.first << " " << p.second << endl;

    return 0;
}