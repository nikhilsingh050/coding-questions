//Problem: Given weights and values of n items, put these items in a knapsack of capacity W to get the
//maximum total value in the knapsack.

#include<bits/stdc++.h>
using namespace std;



//Recursive Solution:
//Time Complexity: O(2^n)

int knapSack(int w, int weight[], int value[], int n)
{
    if(w==0 || n==0)
        return 0;

    int maxw;

    //if current weight is more than the remaining weight -> not included
    if(w<weight[n-1])
        maxw = knapSack(w,weight,value,n-1);

    //Two ways:
    //1. we use the current weight
    //2. we don't use the current weight
    else
        maxw = max(value[n-1] + knapSack(w-weight[n-1],weight,value,n-1) , knapSack(w,weight,value,n-1));

    return maxw;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////

//Dynamic Programming Solution:

//Time Complexity: O(nm)
//Space Complexity: O(nm)

//keywords: include ith weight(row) or not for j remaining weight

//Two ways:
//1. we use the current weight
//2. we don't use the current weight

int knapSackDP(int w, int weight[], int value[], int n)
{
    int memo[n+1][w+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0; j<=w; j++)
        {
            //base cases
            if(i==0 || j==0)
                memo[i][j]=0;

            //current weight is greater than required weight -> we cannot use it
            else if(weight[i-1]>j)
                memo[i][j] = memo[i-1][j];
            else
                memo[i][j] = max(value[i-1] + memo[i-1][j-weight[i-1]] , memo[i-1][j]);
        }
    }
    return memo[n][w];
}


int main()
{
    int val[] = {30,70,50,60};
    int wt[] = {2,4,3,5};
    int W = 5;
    int n = sizeof(val)/sizeof(val[0]);
    //cout<<knapSack(W, wt, val, n);
    cout<<knapSackDP(W, wt, val, n);
    return 0;
}
