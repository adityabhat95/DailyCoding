/*
Problem : The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.
Hint: The basic equation of a circle is x2 + y2 = r2.
Solution : Using Monte Carlo Simulation, the value of Pi is calculated as the ratio, pi = 4*pts in circle/pts in square
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ITER 10000000
using namespace std;
int main() {
  int sqr_pt = 0, cir_pt = 0;
  srand(time(NULL));
  for(int i=0;i<MAX_ITER;i++)
  {
  double x =((double)rand()/RAND_MAX);
  double y =((double)rand()/RAND_MAX);
  sqr_pt++;
  if(((x*x)+(y*y))<=1.00)
  cir_pt++;
  }
  cout<<"No of points in the square is "<<sqr_pt<<endl;
  cout<<"No of points in the circle is "<<cir_pt<<endl;
  double pi_val =(double) (4.00*cir_pt/sqr_pt);
  cout<<"The approx value of Pi is "<<pi_val<<endl;
  return 0;
}
