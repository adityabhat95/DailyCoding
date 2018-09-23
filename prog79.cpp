/*
Problem : Given an array of integers, write a function to determine whether the array could become non-decreasing by modifying 
		  at most 1 element.
		  For ex : For example, given the array [10, 5, 7], you should return true, since we can modify the 10 into a 1 to make 
		  the array non-decreasing.
		  Given the array [10, 5, 1], you should return false, since we can't modify any one element to get a non-decreasing array.
Solution : Check for subsequent elements if the difference is positive or negative. If the numbers of negative number is 1, then the
		   function can return whether it's valid or not.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
bool helper(int arr[])
{
	int size = sizeof(arr)/sizeof(arr[0]);
	int count=0;
	for(int i=0;i<size-1;i++)
		if((arr[i+1]-arr[i])<0)
			count++;
			
	if(count == 1)
		{
		cout<<"The array can be made non-decreasing";
		return true;
		}
	else
		{
		cout<<"The array cannot be made non-decreasing";
		return false;
		}
}
int main()
{
	int arr[] = {10,5,1};
	bool res = helper(arr);
	return 0;
}
