/*
Problem : Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
          For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

          Follow-up: Can you do this in O(N) time and constant space?

Solution : Use a dynammic programming approach where you choose betweent the max
*/
#include<iostream>
using namespace std;
int SumNonAdjacent(int arr[],int n)
{
    int maxSum[n+1];

    maxSum[0] = arr[0];
    maxSum[1] = max(arr[0],arr[1]);

    for(int i=2;i<n;i++)
    {
        maxSum[i] = max(maxSum[i-1],maxSum[i-2]+arr[i]);
    }
    return maxSum[n-1];
}


int main()
{
    int arr[] = {5,1,1,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int result = SumNonAdjacent(arr,len);
    cout<<"The maximum obtained sum is "<<result<<endl;
    return 0;
}
