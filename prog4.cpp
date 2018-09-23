/*
Author : Aditya Bhat
Problem : Given an array of integers find the first missing positive integer in linear time

*/
#include<limits>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[] ={1,2,0};
	int i;
	int length = sizeof(arr)/sizeof(arr[0]);
	int sum = 0;
	int min = std::numeric_limits<int>::max();
	int max = std::numeric_limits<int>::min();
	int res = 0;
	int res_sum = 0;
	//Iterate over the list of integer, find the maximum and minimum element
	for(i=0;i<length;i++)
	{
		if(arr[i]>0)
		{
			sum += arr[i];
			if(arr[i]>max)
			max = arr[i];
			if(arr[i]<min)
			min = arr[i];
		}
	}

	if(min==1)
	{
		res_sum = max * (max+1) / 2;
		res = res_sum - sum;
		if(res == 0)
		res = max + 1;
	}
	else
	{
		res = 1;
	}

	cout<<"The missing number is "<<res<<endl;

	return 0;
}
