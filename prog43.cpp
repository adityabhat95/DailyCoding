/*
Problem : Implement a stack that has the following methods:
          push(val), which pushes an element onto the stack
          pop(), which pops off and returns the topmost element of the stack.
          If there are no elements in the stack, then it should throw an error or return null.
          max(), which returns the maximum value in the stack currently.
          If there are no elements in the stack, then it should throw an error or return null.
Solution :
*/
#include<iostream>
using namespace std;
#define MAX 1000
class Stack{

    public:
    int top;
    int maxi;
    int arr[MAX];

    Stack(){
    top = -1;
    maxi = INT_MIN;
    }

    bool Stack::isEmpty()
    {
        return (top==-1?true:false);
    }

    void Stack::push(int x)
    {
        top++;
        arr[top]=x;
        if(x>maxi)
        maxi = x;
    }
    int Stack::pop()
    {
        if(top<0){
            cout<<"Error";
            return;
        }
        else
        {
            top = top-1;
            return arr[top+1];
        }

    }



}
int main(){

    return 0;
}
