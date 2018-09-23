/*
Author : Aditya Bhat
Problem : Given an array of integers, create another array which contains the product of the entire array except that element without division
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{

  // Use 2 arrays
  // - left which has product of the elements of all elements to the left
  // - right which has product of the elements of all elements to the right

  int arr[] = {4,2,3,6};
  int length = sizeof(arr)/sizeof(arr[0]);
  int i;
  int prod[length] = {0};
  int left[length] = {0};
  int right[length] = {0};

  left[0]=1;
  right[length-1]=1;
  //Find the products to the left
  for(i=1;i<length;i++)
  left[i]=left[i-1]*arr[i-1];
  //Find the products to the right
  for(i=length-2;i>=0;i--)
  right[i]=right[i+1]*arr[i+1];
  //Find the products as left * right
  for(i=0;i<length;i++)
  {
    prod[i]=right[i]*left[i];
    cout<<prod[i]<<endl;
  }

  return 0;
}
