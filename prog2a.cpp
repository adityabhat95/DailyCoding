/*
Author : Aditya Bhat
Problem 2 : Given an array of integers, create another array which contains the product of the entire array except that element
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{

    int arr[] = { 1, 2, 3, 4};
    int i;
    std::vector<int>arr1;
    int prod = 1;
    int length = sizeof(arr)/sizeof(arr[0]);
    //First find the product of the entire array
    for(i=0;i<length;i++)
    {
        prod *= arr[i];
    }
    //Then make the array by dividing products by the elements
    for(i=0;i<length;i++)
    {
        arr1.push_back(prod / arr[i]);
        cout << arr1[i] <<endl;
    }
    return 0;

}



