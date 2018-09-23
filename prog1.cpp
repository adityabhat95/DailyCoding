/*
Problem : Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

Solution : Use a hash set/unordered set and find the remaining sum as you traverse the list of numbers and check if that number exists in the set, then you have found the 2 numbers which add to k

*/
#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>
using namespace std;
bool AddSum(int arr[],int k,int len)
{
    int i = 0;
    unordered_set<int> myset;
    cout << "The length of the array is "<<len<<endl;
    for(i=0;i<len;i++)
    {
        int temp = k - arr[i];

        if(temp>=0 && myset.find(temp)!=myset.end() )
            return true;

        myset.insert(arr[i]);

    }
    return false;
}

int main()
{
    int arr[] = {1,4,45,6,10,8};
    int k = 16;
    int len = sizeof(arr)/sizeof(arr[0]);
    bool flag = AddSum(arr,k,len);
    cout<<flag<<endl;
    return 0;
}
