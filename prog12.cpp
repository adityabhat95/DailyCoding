/*
Problem :There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
         Given N, write a function that returns the number of unique ways you can climb the staircase.
         The order of the steps matters.

Solution : DP problem
*/
#include<iostream>
using namespace std;
int CountWaySteps(int n)
{
int steps[n+1];

steps[0]=0;
steps[1]=1;
steps[2]=2;
for(int i=3;i<=n;i++)
{
steps[i]=0;
if(i-1>0)
steps[i]+=steps[i-1];
if(i-3>0)
steps[i]+=steps[i-3];
if(i-5>0)
steps[i]+=steps[i-3];
}
return steps[n];
}


int main()
{

    cout<<"The number of ways "<<CountWaySteps(5)<<endl;
    return 0;
}
