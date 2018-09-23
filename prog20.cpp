/*
Problem : Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.

Solution :
*/
#include<iostream>
#include<unordered_set>
using namespace std;
struct Node
{
    int val;
    struct Node* next;
};
struct Node* newNode(int x)
{
    struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
    temp->val = x;
    temp->next = NULL;
    return temp;
}
void dispCont(Node* root)
{
    while(root!=NULL)
    {
    cout<<root->val<<" ";
    root = root->next;
    }
}
struct Node* findCommon(Node* list1,Node* list2)
{
    unordered_set<int> hashset;
    struct Node* temp1=list1;
    struct Node* temp2 = list2;

    while(temp1!=NULL)
    {
        hashset.insert(temp1->val);
        temp1 = temp1->next;
    }

    while(temp2!=NULL)
    {
        if(hashset.find(temp2->val)!=hashset.end())
            return temp2;
        temp2 = temp2->next;
    }
    return NULL;
}
int main()
{
    struct Node* root = newNode(3);
    root->next = newNode(7);
    root->next->next = newNode(8);
    root->next->next->next = newNode(10);
    dispCont(root);
    struct Node* head = newNode(99);
    head->next = newNode(1);
    head->next->next = newNode(10);
    head->next->next->next = newNode(8);
    cout<<endl;
    dispCont(head);

    struct Node* value = findCommon(root,head);
    cout<<"The value contained at the node is "<<value->val<<endl;
    return 0;
}
