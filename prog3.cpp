/*
Problem : Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

Solution : Use Preorder Traversal to serialize the tree, use a marker character
           To deserialize the tree, use the string and read it in a preorder way to create the required nodes
*/
#include<sstream>
#include<iostream>
using namespace std;
//basic struct for the Node of the tree
struct Node
{

    int val;
    Node *right, *left;

};
//Creates a new Node
Node* newNode(int val)
{

    Node* temp = new Node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return (temp);

}
//function to implement serialization of the binary tree
string serialize(Node* root)
{

    if(root==nullptr)
    return "#";

    return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
}
Node* mydeserialize(stringstream& s)
{
    string str;
    getline(s,str,',');
    if(str=="#")
        return NULL;
    else{
    Node* temp = newNode(stoi(str));
    temp->left = mydeserialize(s);
    temp->right = mydeserialize(s);
    return temp;
    }
}

Node* deserialize(string data)
{
    if(data[0]=='#')
        return NULL;
    stringstream s(data);
    return mydeserialize(s);
}
int main()
{
    struct Node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    cout<<serialize(root)<<endl;
    root = deserialize(serialize(root));
    return 0;
}
