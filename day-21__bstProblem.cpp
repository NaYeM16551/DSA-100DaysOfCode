#include <bits/stdc++.h>
#include "headerFile/tree.h"

#define trav(i, v) for (auto &i : v)
#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

void convertBstIntoSortedLinkedList(TreeNode *root, TreeNode *&head)
{
    if (!root)
        return;
    convertBstIntoSortedLinkedList(root->right, head);
    root->right = head;
    if (head)
        head->left = root;
    head = root;
    convertBstIntoSortedLinkedList(root->left, head);
}

TreeNode *mergeTwoLinkedList(TreeNode *head1, TreeNode *head2)
{
    
    TreeNode *head = nullptr;
    TreeNode *tail = nullptr;


    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            if (!head)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
           
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
               
            }
        }
        else
        {
            if (!head)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
                
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
      
    }

    // Connect remaining nodes from head1, if any
    if (head1)
    {
        if (!head)
        {
            head = head1;
            tail=head;
            head1=head1->right;
        }
        else
        {
            tail->right = head1;
            head1->left = tail;
            head1=head1->right;
        }
    }

    // Connect remaining nodes from head2, if any
    if (head2)
    {
        if (!head)
        {
            head = head2;
            tail=head2;
            head2=head2->right;
        }
        else
        {
            tail->right = head2;
            head2->left = tail;
            head2=head2->right;
        }
    }

    return head;
}
void printLL(const TreeNode* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
    cout<<endl;
}
TreeNode* mergeTwoLLRecursive(TreeNode* head1, TreeNode*head2)
{
    if(!head1)
    {
       return head2;
    }
    if(!head2)
    {
        
       return head1;
    }
    TreeNode* head;
    if(head1->data < head2->data)
    {
        head=head1;
        auto link=mergeTwoLLRecursive(head1->right,head2);
        head->right=link;
        if(link)
         link->left=head;
       
    }
    else
    {
        head=head2;
        auto link=mergeTwoLLRecursive(head1,head2->right);
        head->right=link;
        if(link)
         link->left=head;

    }
    return head;
}
void printLLR(TreeNode* tail)
{
    while(tail)
    {
        cout<<tail->data<<" ";
        tail=tail->left;
    }
    cout<<endl;

}
TreeNode* sortedLLtoBst(TreeNode* &head,int n)
{
    if(n<=0 || !head)
      return nullptr;
    TreeNode* left=sortedLLtoBst(head,n/2);
    TreeNode* root=head;
    root->left=left;
    head=head->right;
    root->right=sortedLLtoBst(head,n-n/2-1);
    return root;



}
int countNodes(TreeNode* head)
{
    if(!head) return 0;
    return 1+countNodes(head->right);
}
int main()
{
    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;
    ifstream fin("input.txt");
    int data;
    fin >> data;
    while (data != -1)
    {
        root1 = insertIntoBst(root1, data);
        fin >> data;
    }
    fin >> data;
    while (data != -1)
    {
        root2 = insertIntoBst(root2, data);
        fin >> data;
    }
    TreeNode *head1 = nullptr;
    TreeNode *head2 = nullptr;

    convertBstIntoSortedLinkedList(root1, head1);
    if(head1)
     head1->left = nullptr;
    convertBstIntoSortedLinkedList(root2, head2);
    if(head2)
     head2->left = nullptr;
   auto head=mergeTwoLLRecursive(head1, head2);
   auto root=sortedLLtoBst(head,countNodes(head));
   levelOrderTraversal(root);
   
}