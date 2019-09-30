/*Staircase Problem:
Davis has a number of staircases in his house and he likes to
climb each staircase 1, 2 or 3 steps at a time. Being a very
precocious child, he wonders how many ways there are to reach the
top of the staircase.*/



// Using recursion
//Time Complexity: O(3^n)
//Space Complexity: O(1)
int stepPerms(int n) {
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    int count = stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3);
    return count;
}




//Using memoization in recursion
//Time Complexity: O(n)
//Space Complexity: O(n)
int countWays(int n, int memo[])
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(memo[n]==0)
    {
        memo[n]=countWays(n-1,memo) + countWays(n-2,memo) + countWays(n-3,memo);
    }
    return memo[n];
}

int stepPerms(int n)
{
    if(n<0)
        return 0;
    int memo[n+1]={0};
    return countWays(n,memo);
}




//Using Dyanamic Programming -> to avoid recursion overhead
//(iterative and tabulation)
//Time Complexity: O(n)
//Space Complexity: O(n)
int stepPerms(int n)
{
    if(n<0)
        return 0;
    int memo[n+1];
    memo[0]=1;
    memo[1]=1;
    memo[2]=2;
    for(int i=3;i<=n;i++)
        memo[i]=memo[i-1] + memo[i-2] + memo[i-3];
    return memo[n];
}




//Using Dynamic Programming(Optimizing memo space)
//we only need to store the last three values to find the next value.
//Time Complexity: O(n)
//Space Complexity: O(1)
int stepPerms(int n)
{
    if(n<0)
        return 0;
    if(n<=1)
        return 1;
    int memo[]={1,1,2};
    int count;
    for(int i=3;i<=n;i++)
    {
        count= memo[0] + memo[1] + memo[2];
        memo[0]=memo[1];
        memo[1]=memo[2];
        memo[2]=count;
    }
    return memo[2];
}
