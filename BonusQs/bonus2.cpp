/*
Problem : Given a binary tree, count the number of nodes
Solution : Solve using recursion
*/
#include<iostream>
using namespace std;
struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int x)
{
    struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
    temp->val = x;
    temp->right = NULL;
    temp->left = NULL;
}
int countNodes(Node* root)
{
    if(root==NULL)
    return 0;

    return 1+countNodes(root->left)+countNodes(root->right);
}

int main()
{

Node *root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->right->left = newNode(4);
root->right->right = newNode(5);

cout<<"The number of nodes in the tree is "<<countNodes(root)<<endl;
return 0;
}





