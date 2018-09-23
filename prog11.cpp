/*
Problem : Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

Solution : This problem can be solved by using Trie Data Structure
*/
#define ALPHABET_SIZE 26
#include<iostream>

using namespace std;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode* newNode(void)
{
    struct TrieNode* temp = (struct TrieNode*) malloc (sizeof(struct TrieNode));
    temp->isEndOfWord = false;

    for(int i=1;i<=ALPHABET_SIZE;i++)
    {
    temp->children[i-1] = NULL;
    }

    return temp;
}

void insert(TrieNode* root, string word)
{
    TrieNode* temp = root;

    int len = word.length();

    for(int i=0;i<len;i++)
    {
        int index = (int)(word[i]-'a');
        if(temp->children[index]==NULL)
        temp->children[index] = newNode();

        temp = temp->children[index];
    }

    temp->isEndOfWord=true;
    cout<<word<<" is inserted"<<endl;
}

bool search(TrieNode* root, string word)
{
    TrieNode* temp = root;
    int len = word.length();

    for(int i=0;i<len;i++)
    {
    int index = (int)(word[i]-'a');
    if(temp->children[index]==NULL)
        return false;

    temp = temp->children[index];
    }

    if(temp->isEndOfWord==true)
        return true;

    return false;

}




int main()
{
    TrieNode* root = newNode();
    insert(root,"hello");
    bool res = search(root,"hell");
    cout<<" The result is "<<res<<endl;
    return 0;
}
