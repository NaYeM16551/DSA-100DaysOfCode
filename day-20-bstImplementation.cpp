#include <bits/stdc++.h>
#include "headerFile/tree.h"

#define trav(i, v) for (auto &i : v)
#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

TreeNode *insertIntoBst(TreeNode *root, int data)
{
    if (!root)
        return new TreeNode(data);
    if (data > root->data)
        root->right = insertIntoBst(root->right, data);
    else
        root->left = insertIntoBst(root->left, data);
    return root;
}
TreeNode *findMax(TreeNode *node)
{
    while ( node->right)
        node = node->right;
     return node;   
}
// function to delete a node from BST.
TreeNode *deleteNode(TreeNode *root, int x)
{
    // your code goes here
    if (!root)
        return root;
    else if (root->data == x)
    {

        // 0 child
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }

        // 1 child
        //  left
        if (root->left && !root->right)
        {
            auto temp = root->left;
            delete root;
            return temp;
        }

        // right
        if (root->right && !root->left)
        {
            auto temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        watch(root->data);
        auto maxValue = findMax(root->left)->data;
        watch(maxValue);
        root->data = maxValue;
        root->left = deleteNode(root->left, maxValue);
        return root;
    }
    else if (x > root->data)
    {
        root->right = deleteNode(root->right, x);
        return root;
    }
    else
    {
        root->left = deleteNode(root->left, x);
        return root;
    }
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int pre=-1,succ=-1;
    auto temp=root;
    while(temp->data != key)
    {
        if(key > temp->data)
        {
            pre=temp->data;
            temp=temp->right;
        }
        else
        {
             succ=temp->data;
             temp=temp->left;
        }
    }
    auto leftTree=temp->left;
    auto rightTree=temp->right;
    //finding max in leftSubtree
    while(leftTree)
    {
        pre=leftTree->data;
        leftTree=leftTree->right;

    }
    //finding min in rightSubtree
    while(rightTree)
    {
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    return {pre,succ};
}

// int main()
// {
//     TreeNode *root = nullptr;
//     ifstream fin("input.txt");
//     int data;
//     fin >> data;
//     while (data != -1)
//     {
//         root = insertIntoBst(root, data);
//         fin >> data;
//     }
//     int key;
//     fin>>key;
//     auto ans=predecessorSuccessor(root,key);
//     cout<<ans.first <<" "<< ans.second<<endl;
// }