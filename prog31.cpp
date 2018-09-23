/*
Problem : The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other.
          For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.
          Given two strings, compute the edit distance between them.
Solution : Use DP to solve this
*/
#include<iostream>
using namespace std;
int min_3(int x, int y, int z)
{
    return min(min(x,y),z);
}
int EditDistanceDP(string src, string tgt, int len_src, int len_tgt)
{
    int cost[len_src+1][len_tgt+1];
    for(int i=0;i<=len_src;i++)
    {
        for(int j=0;j<=len_tgt;j++)
        {
            //If the source string is empty then the cost is the value of j
            //Else if the target string is empty then the cost is the value of i
            if(i==0)
            cost[i][j] = j;

            else if(j==0)
            cost[i][j] = i;

            else if(src[i-1]==tgt[j-1])//same as previous character doesn't add cost
            cost[i][j] = cost[i-1][j-1];

            else
            cost[i][j] = 1 + min_3(cost[i-1][j-1],cost[i][j-1],cost[i-1][j]);//replace,insert,remove
       }

    }

    return cost[len_src][len_tgt];
}
int main()
{
    string src = "kitten";
    string tgt = "sinday";
    int cost = EditDistanceDP(src,tgt,src.length(),tgt.length());
    cout<<"The Edit Distance from "<<src<<" to "<<tgt<<" is "<<cost<<endl;

}
