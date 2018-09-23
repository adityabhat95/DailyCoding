/*
Problem : Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first,
          the Gs come second, and the Bs come last. You can only swap elements of the array.
          Do this in linear time and in-place.
          For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
Solution : Iterate over the entire array once and get a count on the number of 'R','G' & 'B's and then place them in the array
*/
#include<iostream>
using namespace std;
void segregateChars(char* arr, int len)
{
    int cR=0;
    int cG=0;
    int cB=0;
    //get the count of characters in the array
    for(int i=0;i<len;i++)
    {
        if(arr[i]=='R')
        cR++;
        else if(arr[i]=='G')
        cG++;
        else if(arr[i]=='B')
        cB++;
    }
    //based on the counts replace inplace in the array
    for(int i=0;i<len;i++)
    {
    if(i<cR)
        arr[i]='R';
    else if(i>=cR && i<(cR+cG))
        arr[i]='G';
    else
        arr[i]='B';
    }
    cout<<"The contents of the array are :";
    for(int i=0;i<len;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    char arr[]={'G', 'B', 'R', 'R', 'B', 'R', 'G'};
    int len = sizeof(arr)/sizeof(arr[0]);
    segregateChars(arr,len);
    return 0;
}
