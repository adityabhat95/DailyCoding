/*
Problem : Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
Solution : Using the concept of Reservoir Sampling with k=1 instead or k with larger values
*/
#include<iostream>
#include<time.h>
using namespace std;
void findRandom(int stream[],int n, int k)
{
    int i=0;
    int mem[k];
    srand(time(NULL));
    for(i=0;i<k;i++)
    {
        mem[i]=stream[i];
    }
    for(;i<n;i++)
    {
        int j = rand() % (i+1);
        if(j<k)
        {
        mem[j] = stream[i];
        }
    }
    cout<<"The randomly generated "<<k<<" elements are "<<endl;
    for(i=0;i<k;i++)
    {
    cout<<mem[i]<<" ";
    }
}
int main(){
    int stream[] = {12,1,3,56,73,24,-3,-67,51,104};
    int n = sizeof(stream)/sizeof(stream[0]);
    int k = 1;
    findRandom(stream,n,k);
    return 0;
}
