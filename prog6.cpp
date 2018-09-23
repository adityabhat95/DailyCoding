/*
Problem :
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and
the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a
get(index) which returns the node at index.
*/
#include<iostream>
using namespace std;

struct Node
{
    int val;
    struct Node* both;
};

struct Node* XOR(struct Node* a, struct Node* b)
{
    return (struct Node*) ((uintptr_t)(a)^(uintptr_t)(b));
}

void add(struct Node** headref, int element)
{

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->val = element;

    newNode->both = XOR(*headref,NULL);

    //the address of the previous node can be found out using the XOR of current and next




}







int main()
{

    return 0;
}
