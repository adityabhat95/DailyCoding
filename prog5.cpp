/*
Problem : cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4

Solution : Basic implementation using a struct

*/
#include<iostream>
using namespace std;
struct Pair
{
    int a;
    int b;
};
Pair cons(int x, int y)
{
    Pair p;
    p.a = x;
    p.b = y;
    return p;
}
int car(Pair p)
{
    return p.a;
}
int cdr(Pair p)
{
    return p.b;
}
int main()
{
    Pair p;
    p = cons (10,20);
    cout<<"values are "<<p.a<<" "<<p.b<<endl;
    cout<<car(p)<<endl;
    cout<<cdr(p)<<endl;


    return 0;
}
