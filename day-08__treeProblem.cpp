#include <bits/stdc++.h>

#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";
#define trav(i, v) for (auto &i : v)
#include "headerFile/tree.h"

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

vector<int> morrisTraverSalInorder(TreeNode *root)
{
       vector<int> ans;
        while(root)
        {
            if(root->left==nullptr)
            {
                ans.push_back(root->data);
                root=root->right;
            }
            else
            {
                auto temp=root->left;
                while(temp->right && temp->right!=root)
                  temp=temp->right;
                if(temp->right==root)
                {
                    temp->right=nullptr;
                    ans.push_back(root->data);
                    root=root->right;
                }
                else
                {
                    temp->right=root;
                    root=root->left;
                }
                
                
                
                
            }
        }
        return ans;
}

vector<int> morrisTraverSalPreorder(TreeNode *root)
{
     vector<int> ans;
        while(root)
        {
            if(root->left==nullptr)
            {
                ans.push_back(root->data);
                root=root->right;
            }
            else
            {
                auto temp=root->left;
                while(temp->right && temp->right!=root)
                  temp=temp->right;
                if(temp->right==root)
                {
                    temp->right=nullptr;
                   
                    root=root->right;
                }
                else
                {
                    ans.push_back(root->data);
                    temp->right=root;
                    root=root->left;
                }
                
                
                
                
            }
        }
        return ans;
}
vector<int> morrisTraversalPostorder(TreeNode *root)
{
    auto current = root;
    vector<int> post;
    while (current)
    {
        if (current->right == nullptr)
        {
            post.push_back(current->data); // Use current->data
            current = current->left;
        }
        else
        {
            // predecessor finding
            auto prev = current->right;
            while (prev->left && prev->left != current)
                prev = prev->left;
            if (prev->left == current)
            {
                prev->left = nullptr;
                current = current->left;
            }
            //restoring
            else
            {
                prev->left = current;
                post.push_back(current->data); // Use current->data
                current = current->right;
            }
        }
    }
    reverse(post.begin(), post.end()); // Reverse the result to get postorder
    return post;
}

int main()
{
    TreeNode *root = nullptr;
    ifstream fin("input.txt");
    buildTreeFromLevelOrder(root, fin);
   
   auto ans=morrisTraverSalInorder(root);
   show(ans)

   ans.clear();

   ans=morrisTraverSalPreorder(root);
   show(ans);

   ans.clear();

   ans=morrisTraversalPostorder(root);
   show(ans);

    
  
    return 0;
}