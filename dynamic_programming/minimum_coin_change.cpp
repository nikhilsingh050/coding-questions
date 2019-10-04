//Find minimum number of coins that make a given value.
//Given solutions work only when a solution exists.

#include<bits/stdc++.h>
using namespace std;



//Recursive Solution:
//Try all the possible ways.

//Time complexity: O(n^m)


int minCoins(int coins[],int n,int amount)
{
    if(amount==0)
        return 0;

    int minCount = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(coins[i]<=amount)
        {
            int res = 1 + minCoins(coins,n,amount-coins[i]);
            minCount=min(minCount,res);
        }
    }
    return minCount;
}





////////////////////////////////////////////////////////////////////////////

//Using Memoization:

//Storing the result of recursion in a table.
//top down approach

//Time Complexity: O(nm)
//Space Complexity: O(m)


int minCoinsUtility(int coins[],int n,int amount, int memo[])
{
    if(amount==0)
        return 0;

    int minCount = INT_MAX;

    if(memo[amount]!=INT_MAX)
        return memo[amount];

    for(int i=0;i<n;i++)
    {
        if(coins[i]<=amount)
        {
            int res = 1 + minCoinsUtility(coins,n,amount-coins[i],memo);
            minCount=min(minCount,res);
        }
    }
    memo[amount]= minCount;
    return memo[amount];
}
int minCoinsMemo(int coins[],int n,int amount)
{
    int memo[amount+1];
    fill(memo,memo+amount+1,INT_MAX);

    memo[0]=0;
    return minCoinsUtility(coins,n,amount,memo);
}





/////////////////////////////////////////////////////////////////////////////

//Dynamic Programming Solution:

//Time Complexity: O(nm)
//Space Complexity: O(m)


int minCoinsDP(int coins[],int n,int amount)
{
    int memo[amount+1];
    fill(memo,memo+amount+1,INT_MAX);

    memo[0]=0;

    for(int i=1;i<=amount;i++)
    {
        for(int c=0;c<n;c++)
        {
            if(coins[c]<=i)
                memo[i]=min(memo[i],1+memo[i-coins[c]]);
        }
    }

    return memo[amount];
}



int main()
{
    int coins[] =  {1, 2, 5};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;

    //cout << "Minimum coins required is: "<< minCoins(coins, m, V);
    //cout << "Minimum coins required is: "<< minCoinsMemo(coins, m, V);
    cout << "Minimum coins required is: "<< minCoinsDP(coins, m, V);

    return 0;
}
