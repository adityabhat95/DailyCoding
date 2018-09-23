/*
Problem : Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).
          For example, given the string "([])[]({})", you should return true.
          Given the string "([)]" or "((()", you should return false.
Solution : This problem can be solved by using a stack and comparing the top of the stack
*/
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
bool CheckBalance(string s)
{

    std::stack<char> parens;
    int len = s.length();

    for(int i =0;i<len;i++)
    {
        if(s[i]==')'&&parens.top()=='(')
        parens.pop();
        else if(s[i]==']'&&parens.top()=='[')
        parens.pop();
        else if(s[i]=='}'&&parens.top()=='{')
        parens.pop();
        else
        parens.push(s[i]);
    }

    if(!parens.empty())
    return false;

    return true;
}
int main()
{
    string s1 = "([])[]({})";
    string s2 = "((()";
    string s3 = "([)]";
    string s4 = "(())(())()()()";
    bool a = CheckBalance(s1);
    cout<<"The value of a is "<<a<<endl;
    a = CheckBalance(s2);
    cout<<"The value of a is "<<a<<endl;
    a = CheckBalance(s3);
    cout<<"The value of a is "<<a<<endl;
    a = CheckBalance(s4);
    cout<<"The value of a is "<<a<<endl;
    return 0;
}
