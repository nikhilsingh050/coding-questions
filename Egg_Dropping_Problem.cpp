//Egg Dropping Problem:
//Find the minimum number of trials required to find the critical floor in worst case.
//critical floor-> the floor upto which dropping egg wont break.
//Assumption: An egg that survives a fall can be used again.

//Start from x=1 to kth floor.
//Two cases:
//If egg breaks: GO DOWN one floor and calculate for remaining floor below -> (x-1).
//If egg doesn't break: calculate for the remaining floors above. -> (k-x)


#include<bits/stdc++.h>
using namespace std;



/////////////////////////////////////////////////////////////////////////////

//Recursive Solution:

int eggDrop(int n, int k)
{
    //when there are 0 or 1 floors
    if(k==0 || k==1)
        return k;

    //only 1 egg -> in worst case we have to drop for every floor
    if(n==1)
        return k;

    int min=INT_MAX;

    //consider trials from 1st floor to kth floor
    //and return the minimum
    for(int i=1;i<=k;i++)
    {
        //we use max to cover the worst cases
        int result = 1 + max(eggDrop(n-1,i-1),eggDrop(n,k-i));
        if(result<min)
            min=result;
    }
    return min;
}



////////////////////////////////////////////////////////////////////////

//Using Dynamic Programming:

int eggDrop(int n, int k)
{
    int memo[n+1][k+1];

    //for 0 and 1st floors -> we only need 0 and 1 trials
    for (int i = 1; i <= n; i++)
    {
        memo[i][1] = 1;
        memo[i][0] = 0;
    }

    //for 1 egg -> in worst case we have to try for all floors
    for (int i = 1; i <= k; i++)
        memo[1][i] = i;

    //filling table for rest of the cases
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            memo[i][j] = INT_MAX;

            //for every floor from 1st to jth floor
            for (int x = 1; x <= j; x++)
            {
                int result = 1 + max(memo[i-1][x-1], memo[i][j-x]);
                if (result < memo[i][j])
                    memo[i][j] = result;
            }
        }
    }

    return memo[n][k];
}


int main()
{
    int n = 6, k = 27;
    cout << "Minimum number of trials in worst case: "<< eggDrop(n, k) << endl;
    return 0;
}
