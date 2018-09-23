/*
Problem : Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
          For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8]
Solution : Brute Force Approach - O(nk) time where n - length of array and k - no. of elements
*/
#include<iostream>
#include<cstdint>
#include<limits.h>
using namespace std;

int main()
{
    int arr[] = {10,5,2,7,8,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    int n = len;
    int k = 3;
    for(int i = 0;i<n-k+1;i++)
    {
        auto max_ele = INT_MIN;
        for(int j=i;j<i+k;j++)
        {

        if(arr[j]>max_ele)
            max_ele = arr[j];

        }
        cout<<max_ele<<" ";
    }
    cout<<endl;





    return 0;
}
