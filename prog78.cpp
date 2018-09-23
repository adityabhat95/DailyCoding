/*
Problem : Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.
Solution : Use a heap of k elements and update accordingly.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
	int val;
	struct Node* next;
};
struct Node* NewNode(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->val = x;
	temp->next = NULL;
	return temp;
}
void display(struct Node* root)
{
	while(root!=NULL)
	{
		cout<<root->val<<" ";
		root = root->next;
	}
}
int main()
{
	Node* root = NewNode(1);
	root->next = NewNode(4);
	root->next->next = NewNode(7);
	cout<<"Display List 1:";
	display(root);
	cout<<endl;
	
	Node* l1 = NewNode(2);
	l1->next = NewNode(5);
	l1->next->next = NewNode(8);
	cout<<"Display List 2:";
	display(l1);
	cout<<endl;
	
	Node* l2 = NewNode(3);
	l2->next = NewNode(6);
	l2->next->next = NewNode(9);
	cout<<"Display List 3:";
	display(l2);
	cout<<endl;
	
	
	return 0;
}
