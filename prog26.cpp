/*
Problem : Given a singly linked list, remove the kth last element from the list

Solution : Use the fast ptr & slow ptr concept
*/
#include<iostream>
using namespace std;
struct Node
{
    int val;
    struct Node* next;
};
struct Node* newNode(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = x;
    temp->next = NULL;
    return temp;
}
void RemoveKthElement(struct Node* root,int k)
{
    struct Node* fast = root;
    struct Node* slow = root;
    int i=0;
    while(fast!=NULL)
    {
    i++;
    fast = fast->next;
    if(i>(k+1))
    slow = slow->next;
    }
    struct Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

}
void DisplayList(struct Node* root)
{
    struct Node* temp = root;
    cout<<endl<<"The contents of the list are : ";
    while(temp!=NULL)
    {
    cout<<temp->val<<" ";
    temp = temp->next;
    }
}
int main()
{
    struct Node* root = newNode(10);
    root->next = newNode(7);
    root->next->next = newNode(4);
    root->next->next->next = newNode(-8);
    struct Node* temp = root->next->next->next;
    temp->next = newNode(3);
    temp->next->next = newNode(2);
    temp->next->next->next = newNode(-1);
    int k = 3;
    RemoveKthElement(root,k);
    DisplayList(root);
    RemoveKthElement(root,k);
    DisplayList(root);
    RemoveKthElement(root,k);
    DisplayList(root);
    RemoveKthElement(root,k);
    DisplayList(root);
    return 0;
}
