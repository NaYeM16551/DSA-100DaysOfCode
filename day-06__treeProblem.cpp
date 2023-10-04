#include <bits/stdc++.h>

#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";
#define trav(i, v) for (auto &i : v)
#include "headerFile/tree.h"

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

bool pathFinder(TreeNode *root, int node, vector<int> &ans)
{
    if (!root)
        return false;
    if (root->data == node)
        return true;
    auto leftAns = pathFinder(root->left, node, ans);
    auto rightAns = pathFinder(root->right, node, ans);
    if (leftAns || rightAns)
    {
        ans.push_back(root->data);
        return true;
    }
    return false;
}
unordered_map<TreeNode *, int> m;
int getMaxSum(TreeNode *root)
{
    // Add your code here
    // recursive code
    // optimize -> 2 lines

    // with node
    // case 1
    if (!root)
        return 0;
    if (m[root])
        return m[root];
    int withnode = root->data;
    // call your grandchildren

    if (root->left)
    {
        withnode += getMaxSum(root->left->left);
        withnode += getMaxSum(root->left->right);
    }

    if (root->right)
    {
        withnode += getMaxSum(root->right->left);
        withnode += getMaxSum(root->right->right);
    }
    // case 2
    // without node

    // call your children
    int withoutnode = getMaxSum(root->left) + getMaxSum(root->right);

    return m[root] = max(withnode, withoutnode);
}

    bool solve(TreeNode * root, int &k, int node, int &ans)
    {
        if (!root)
            return false;
        if (root->data == node)
            return true;
        auto leftAns = solve(root->left, k, node, ans);
        auto rightAns = solve(root->right, k, node, ans);
        if (leftAns || rightAns)
        {
            k--;
            if (!k)
                ans = root->data;
            return true;
        }
        return false;
    }

    int main()
    {
        TreeNode *root = nullptr;
        ifstream fin("input.txt");
        buildTreeFromLevelOrder(root, fin);
        int ans=getMaxSum(root);
        cout<<ans<<endl;
        return 0;
    }