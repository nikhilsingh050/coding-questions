//given the price array with stock price on ith day of the week.
//best buy and sell time to maximize profit.


#include<bits/stdc++.h>
using namespace std;


///////////////////////////////////////////////////////////////////////

//Dyanamic Programming Solution:

//Maximum profit with k given transaction.

//Time Complexity: O(k*n*n)
//Space Complexity: O(k*n)

//Can be optimized by calculating maxdiff in constant time -> i dont understand how.(yet)


void maxProfit(int prices[],int n, int k)
{
    int dp[k+1][n+1];

    //maximum profit including (j-1)th day is stored in jth column
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            //Base Case:
            //for 0 transactions and 0 days -> max profit = 0
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }

            //Two ways:
            //1. we sell on current day
            //2. we dont sell on current day

            //if we sell on current day:
            //we will find maximum difference between current day and all previous days.
            //profit = max(differences + profit of the remaining previous days)
            int maxd=INT_MIN;
            for(int m=0;m<j-1;m++)
            {
                maxd = max(maxd, prices[j-1]-prices[m] + dp[i-1][m]);
            }

            //New profit = max (profit if we sell on current day , if we dont sell on current day)
            dp[i][j]= max(maxd, dp[i][j-1]);
        }
    }
    cout<<dp[k][n];
}






///////////////////////////////////////////////////////////////////////

//one transaction only.

//return maximum profit.
//find maximum difference -> between current element and minimum element till current


int maxProfit(int prices[],int n) {

    int mini=INT_MAX;
    int maxdiff = 0;

    for(int i=0;i<n;i++)
    {
        maxdiff = max(maxdiff,prices[i]-mini);

        mini = min(mini,prices[i]);
    }
    return maxdiff;
}






////////////////////////////////////////////////////////////////////////

//any number of transactions.

//return buy, sell days.
//find local maxima and local minima.


void stockBuySell(int a[],int n)
{
    vector<int> buy,sell;

    for(int i=0;i<n-1;i++)
    {
        //local minima -> buy time
        while(i<n-1 && a[i]>=a[i+1])
            i++;
        buy.push_back(i);
        i++;

        //local maxima -> sell time
        while(i<n && a[i]<=a[i+1])
            i++;
        sell.push_back(i);

    }

    for(int i=0;i<buy.size();i++)
        cout<<buy[i]<<" "<<sell[i]<<endl;
}






/////////////////////////////////////////////////////////////////////////

//in any number of transactions.

//print the profit.
//mathematics solution.
//sum of all (peak-valley)


int maxProfitSum(int prices[], int n) {
    int sum=0;
    for(int i=1;i<n;i++)
    {
        //sum of all (peak-valley) values.
        if(prices[i]>prices[i-1])
            sum+=prices[i]-prices[i-1];
    }
    return sum;
}




//////////////////////////////////////////////////////////////////////////

int main()
{
    int price[] = { 10, 22, 5, 75, 65, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    maxProfit(price, n, 2);
}
