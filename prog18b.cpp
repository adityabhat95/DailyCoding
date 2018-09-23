/*
Problem : Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
          For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8]
Solution : Use a priority queue/heap and solve it
*/
#include<iostream>
#include<cstdint>
#include<limits.h>
#include<queue>
using namespace std;

int main()
{
    int arr[] = {10,5,2,7,8,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    int n = len;
    int k = 3;
    std::deque<int> mydq (k,INT_MIN);
    int pos=0;
    for(int i=0;i<k;i++)
    {
        mypq.push(arr[i]);
    }





    return 0;
}
