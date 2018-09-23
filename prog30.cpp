/*
Problem : You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit-width wall and the integer is the height.
          Suppose it will rain and all spots between two walls get filled up.
          Compute how many units of water remain trapped on the map in O(N) time and O(1) space.
          For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.
          Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index
          (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.
Solution : Traverse the array, find the max at left and right at each element and then find the amount of water remaining
*/
#include<iostream>
#include<algorithm>
using namespace std;
int RainDropTrapped(int arr[],int n)
{
    int count = 0;
    int left[n];
    int right[n];
    left[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        left[i] = max(left[i-1],arr[i]);
    }
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i] = max(right[i+1],arr[i]);
    }

    for(int i=0;i<n;i++)
    {
    count += min(left[i],right[i]) - arr[i];
    }
    return count;
}
int main()
{
    int arr[] = {3,1,0,4,2,3,0,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int count = RainDropTrapped(arr,len);
    cout<<"The number of rain drops trapped are : "<<count<<endl;
    return 0;
}
