//total number of unique ways to make a change

#include<bits/stdc++.h>
using namespace std;


//Using Recursion:
int makeChange(int coins[],int n, int amount)
{
    if(amount==0)
        return 1;

    else if(amount<0 || (n<=0 && amount>0))
        return 0;

    int count = makeChange(coins,n-1,amount) + makeChange(coins,n,amount-coins[n-1]);

    return count;
}


/////////////////////////////////////////////////////////////////////////////////////

//Using Dynamic Programming:
//There are two ways:
//1. Dont use current coins -> move 1 row above
//2. Use current coin -> stay in current row, change column to -> current col(amount) - current coin value
//total ways = 1 + 2

int makeChangeDP(int coins[],int n, int amount)
{
    int memo[n+1][amount+1];

    memo[0][0]=1;

    //for amount 0
    for(int i = 0; i <=n; i++)
        memo[i][0] = 1;

    //for 0 coins
    for(int i=1;i<=amount;i++)
        memo[0][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=amount;j++)
        {
            // check if the coin value is less than the amount needed
            if(coins[i-1]<=j)
                memo[i][j] = memo[i-1][j] + memo[i][j-coins[i-1]];

            // just copy the value from the top
            else
                memo[i][j] = memo[i-1][j];
        }
    }
    return memo[n][amount];
}



int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int amount = 10;
    cout<<"Number of ways to make change: "<<makeChangeDP(arr,n,amount);
    return 0;
}
