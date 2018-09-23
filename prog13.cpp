/*
Problem : Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
Solution : Use a sliding window and solve the problem
*/
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int LengthSubstring(string str,int len,int k)
{
    int pos = 0;
    int max_length = 0;
    unordered_set<char> distChars;
    int sub_len = 0;
    for(int i=0;i<k;i++)
    {
    distChars.insert(str[i]);
    }
    sub_len = k;

    for(int i=k;i<len;i++)
    {
        distChars.insert(str[i]);
        if(distChars.size()>k)
        {
        distChars.erase(str[pos++]);
        sub_len = i-pos+1;
        if(sub_len>max_length)
        max_length = sub_len;
        }
        else
        sub_len++;
    }
    if(sub_len>max_length)
        max_length = sub_len;


    return max_length;
}
int main()
{
    string str ("aabacbebebe");
    int len = str.length();
    int k=3;
    cout<<"Length of the substring with "<<k<<" characters is "<<LengthSubstring(str,len,k);
    return 0;
}
