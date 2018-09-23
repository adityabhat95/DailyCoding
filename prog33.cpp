/*
Problem : Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on each new element.
          Recall that the median of an even-numbered list is the average of the two middle numbers.
          For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:
          2,1.5,2,3.5,2,2,2
Solution : Use a 2 heap approach. Use a min heap for the higher elements and a max heap for the lower elements
*/
#include<iostream>
#include<queue>
using namespace std;
float* getMedians(int arr[],int len)
{
    float temp[len];
    std::priority_queue<int> lower;
    std::priority_queue<int, vector<int>, greater<int>> higher;
    std::priority_queue<int> small;
    std::priority_queue<int> large;
    for(int i=0; i<len; i++)
    {
        if(lower.size()==0)
        {
        lower.push(arr[i]);
        }
        else if(arr[i]<lower.top())
        {
        lower.push(arr[i]);
        }
        else
        {
        higher.push(arr[i]);
        }

        small = lower.size()<higher.size() ? lower : higher;
        large = lower.size()>higher.size() ? lower : higher;

        //small.push(large.pop());

        if((small.size()+large.size())%2==0)
        {
        temp[i] = (float)(small.top()+large.top())/2;
        }
        else
        temp[i] = (float)(1.0*small.top());
    }

    return temp;
}
int main()
{
    int arr[] = {2, 1, 5, 7, 2, 0, 5 };
    int len = sizeof(arr)/sizeof(arr[0]);
    float medians[] = getMedians(arr,len);
    for(int i=0;i<len;i++)
    {
        cout<<medians[i]<<",";
    }
    cout<<endl;

    return 0;
}
