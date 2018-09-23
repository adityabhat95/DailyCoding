/*
Problem : Run-length encoding is a fast and simple method of encoding strings.
          The basic idea is to represent repeated successive characters as a single count and character.
          For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".
          Implement run-length encoding and decoding.
          You can assume the string to be encoded have no digits and consists solely of alphabetic characters.
          You can assume the string to be decoded is valid.
Solution : Use a counter and count the letters
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string RunLengthEncoding(string s)
{
    string temp = "";
    int len = s.length();
    char ch = s[0];
    int count = 1;
    for(int i=1;i<len;i++)
    {
    if(s[i]!=ch){
        temp = temp + std::to_string(count) + ch;
        ch = s[i];
        count = 1;
                }
    else{
        count++;
        }
    }
    temp = temp + std::to_string(count) + ch;
    return temp;
}
string DecodeEncoding(string s)
{
    string temp = "";
    int len = s.length();
    string target ="";
    for(int i =0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            temp = temp+s[i];
        }
        else
        {
            int num = std::stoi(temp);
            target = target.append(num,s[i]);
            temp = "";
        }
    }
    return target;
}
int main()
{
    string s = "AAAABBBCCEEAADGHCCDAA";
    string s1 = RunLengthEncoding(s);
    cout<<s1<<endl;
    string s2 = DecodeEncoding(s1);
    cout<<s2<<endl;
    return 0;
}
