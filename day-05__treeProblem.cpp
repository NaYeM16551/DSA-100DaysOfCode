#include <bits/stdc++.h>
#include "headerFile/tree.h"

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

vector<int> verticalOrder(TreeNode *root)
{
    // Your code here
    map<int, vector<int>> mp;
    if (!root)
        return {};
    queue<pair<int, TreeNode *>> q;
    q.push({0, root});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        auto hd = temp.first;
        auto node = temp.second;
        mp[hd].push_back(node->data);
        if (node->left)
            q.push({hd - 1, node->left});
        if (node->right)
            q.push({hd + 1, node->right});
    }
    vector<int> ans;
    for (auto &i : mp)
    {
        sort(i.second.begin(), i.second.end(), greater<int>());
        for (auto &j : i.second)
        {

            // for(auto&k :j.second)
            ans.push_back(j);
        }
    }
    return ans;
}

vector<int> diagonal(TreeNode *root)
{
    // your code here
    // Your code here
    cout<<"Diagonal"<<endl;
    map<int, vector<int>> mp;
    if (!root)
        return {};
    queue<pair<int, pair<int, TreeNode *>>> q;
    q.push({0, {0, root}});
    // mp[0][0].push_back(root->data);
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        auto hd = temp.first;
        auto level = temp.second.first;
        auto node = temp.second.second;
        mp[hd + level].push_back(node->data);
        if (node->left)
            q.push({hd + 1, {level + 1, node->left}});
        if (node->right)
            q.push({hd - 1, {level + 1, node->right}});
    }
    vector<int> ans;
    for (auto &i : mp)
    {
        for (auto &j : i.second)
        {

            // for(auto&k :j.second)
            ans.push_back(j);
        }
    }
    return ans;
}
int main()
{

    TreeNode *root = nullptr;
    ifstream fin("input.txt");
    buildTreeFromLevelOrder(root, fin);
    auto ans = diagonal(root);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}