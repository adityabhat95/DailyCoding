/*
Problem : Invert a binary tree
Solution : Make the pointers point each other
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
};
struct Node* NewNode(int x)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->val = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void helper(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
	struct Node* temp;
	helper(root->left);
	helper(root->right);
		
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	
	}
}
void display(struct Node* root)
{
	if(root==NULL)
		return;
	display(root->left);
	cout<<root->val<<" ";
	display(root->right);
}
int main()
{
	Node* root = NewNode(10);
	root->left = NewNode(5);
	root->right = NewNode(6);
	root->right->left = NewNode(3);
	root->right->right = NewNode(4);
	
	cout<<"Before Inversion:"<<endl;
	display(root);
	helper(root);
	cout<<endl<<"After Inversion:"<<endl;
	display(root);		
}
