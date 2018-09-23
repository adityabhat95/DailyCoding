/*
Problem : The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.
          For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
          You may also use a list or array to represent a set.
Solution : Using bit operations we can solve this problem.
*/
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<vector<char>> PowerSet(vector<char> arr, int len){

    int pow_len = pow(2,len);
    vector<vector<char>> temp;

    for(int i=0; i<pow_len; i++)
    {
    vector<char> t;
        for(int j=0; j<len; j++)
        {
            //This statement indicates that its comparing i & 1 shifted j times
            //This basically checks for each bit set in a number
            if(i & (1<<j))
            {
                t.push_back(arr[j]);
            }
        }
    temp.push_back(t);
    }
    return temp;
}
int main()
{
    vector<char> arr;
    arr.push_back('a');
    arr.push_back('b');
    arr.push_back('c');
    vector<vector<char>> powerSet = PowerSet(arr,arr.size());
    cout<<"The contents of the power set are:"<<endl;
    for(int i=0;i<powerSet.size(); i++)
    {
        cout<<"{";
        for(int j=0; j<powerSet[i].size(); j++)
        cout<<powerSet[i][j]<<",";
        cout<<"}";
        cout<<endl;
    }
    return 0;
}
