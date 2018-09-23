/*
Problem : Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

          For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

Solution : The given sequence is transversed from the end and then recursed on the remaining (n-1) or (n-2) digits and then adding it up
*/
#include<cstring>
#include<iostream>
using namespace std;

int countDecode(char *message,int n)
{
    int sol[n+1];
    sol[0]=1;
    sol[1]=1;

    for(int i=2;i<=n;i++)
    {

    sol[i] = 0;
    //check for the 0s inbetween the message
    if(message[i-1]>'0')
    sol[i] = sol[i-1];
    //to check if the character range is within the limit
    if(message[i-2]=='1'|| (message[i-2]=='2'&& message[i-1] <'7'))
    sol[i] += sol[i-2];

    }
    return sol[n];
}

int main()
{
    char message[] = "22222";
    int result = countDecode(message,strlen(message));

    cout<<"The no. of ways the message can be decoded is "<<result<<endl;
    return 0;

}

