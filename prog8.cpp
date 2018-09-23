/*
Problem : A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
          Given the root to a binary tree, count the number of unival subtrees.

Solution : First, check if the tree is unival and then check for the count of the no. of subtrees which are unival
*/
#include<iostream>
using namespace std;

struct Node
{
    int val;
    struct Node* right;
    struct Node* left;
};
struct Node* newNode(int x)
{

struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
temp->val = x;
temp->right = NULL;
temp->left = NULL;
return temp;
}
bool univalHelper(Node* root, int val)
{
    if(root==NULL)
        return true;

    if(root->val == val)
    {
    return (univalHelper(root->left,root->val) & univalHelper(root->right,root->val));
    }

    return false;
}
bool checkUnival(Node* root)
{
    return univalHelper(root,root->val);
}
int countUnival(Node* root)
{
    if(root==NULL)
    return 0;

    int left = countUnival(root->left);
    int right = countUnival(root->right);

    if(checkUnival(root)==true)
    {
        return (1+left+right);
    }
    else
    {
        return (left+right);
    }
}


int main()
{
    Node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(0);
    root->right->left = newNode(1);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(1);
    root->right->right = newNode(0);

    cout<<"Result is "<<countUnival(root)<<endl;
    return 0;
}
