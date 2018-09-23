/*
Problem : Given the root to a binary search tree, find the second largest node in the tree
Solution : Using  Reverse Inorder traversal, we are able to find the second largest node in the tree
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
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct Node* insert(struct Node* root,int x)
{
    if(root==NULL)
        return newNode(x);

    if(x>root->val)
        root->right = insert(root->right,x);
    else
        root->left = insert(root->left,x);
}


void FindSecondLargestUtil(struct Node* root,int &c)
{
    if(root==NULL || c>=2)
    return;

    FindSecondLargestUtil(root->right,c);
    c++;
    if(c==2)
    {
        cout<<"The second largest value is "<<root->val;
    }
    FindSecondLargestUtil(root->left,c);
}
void FindSecondLargest(struct Node* root)
{
    int c=0;
    FindSecondLargestUtil(root,c);
}

int main()
{
    struct Node* root = newNode(8);
    /*
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left = newNode(3);
    root->left->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right->right = newNode(7);
    root->left->right->left = newNode(4);*/
    insert(root,10);
    insert(root,14);
    insert(root,13);
    insert(root,6);
    FindSecondLargest(root);
    return 0;
}
