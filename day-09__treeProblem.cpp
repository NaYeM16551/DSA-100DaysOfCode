#include <bits/stdc++.h>

#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";
#define trav(i, v) for (auto &i : v)
#include "headerFile/tree.h"

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

int getMaxWidth(TreeNode *root)
{

    // Your code here
    if (!root)
        return 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int ans = INT_MIN;
    int first = 1, last = 0;
    while (!q.empty())
    {
        auto node = q.front();
        auto min = node.second;
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            node = q.front();
            q.pop();
            auto curr_index = node.second - min;
            if (i == 0)
                first = curr_index;
            if (i == size - 1)
                last = curr_index;
            if (node.first->left)
                q.push({node.first->left, 2 * curr_index + 1});
            if (node.first->right)
                q.push({node.first->right, 2 * curr_index + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{
    TreeNode *root = nullptr;
    ifstream fin("input.txt");
    buildTreeFromLevelOrder(root, fin);
}