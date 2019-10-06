/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.
*/


#include<bits/stdc++.h>
using namespace std;




//Recursive Solution:

int decodeWays(string &s, int n)
{
    //base case
    if(n==s.length())
        return 1;

    //check for string length 1 first
    int num1 = s[n]-'0';

    if(num1 == 0)
        return 0;

    //base case
    if(n==s.length()-1)
        return 1;

    //for string of length 2
    int num2 = num1*10 + s[n+1]-'0';
    if(num2>0 || num2<=26)
        return decodeWays(s,n+1) + decodeWays(s,n+2);
    else
        return decodeWays(s,n+1);
}



////////////////////////////////////////////////////////////////////////////

//Using Memoization:
//Top down Approach

int decodeWaysUtil(string &s, int n,int memo[])
{
    if(n==s.length())
        return 1;

    int num1 = s[n]-'0';

    if(num1 == 0)
        return 0;

    if(n==s.length()-1)
        return 1;

    int num2 = num1*10 + s[n+1]-'0';

    if(memo[n]!=-1)
        return memo[n];
    int res;
    if(num2>0 || num2<=26)
        res = decodeWaysUtil(s,n+1,memo) + decodeWaysUtil(s,n+2,memo);
    else
        res = decodeWaysUtil(s,n+1,memo);

    memo[n]=res;
    return res;
}

int decodeWaysMemo(string &s, int n)
{
    int memo[s.length()];
    fill(memo,memo+s.length(),-1);
    return decodeWaysUtil(s,n,memo);
}




///////////////////////////////////////////////////////////////////////////////////

//Dynamic Programming Solution:
//Bottom up Approach

int decodeWaysDP(string s)
{
    int n=s.length();
    if(n==0 || s[0]=='0')
        return 0;

    int dp[n+1];
    fill(dp,dp+n+1,0);

    //base cases
    dp[0]=1;
    dp[1]=1;

    //store result of string of length i
    for(int i=2;i<=n;i++)
    {
        //if last number of the string is valid add the result without it
        if(s[i-1]!='0')
            dp[i]+=dp[i-1];

        //if last two digit is valid -> add the result without them
        int num2=(s[i-2]-'0')*10 + s[i-1]-'0';
        if(num2>0 && num2<=26)
            dp[i]+=dp[i-2];
    }
    return dp[n];
}




int main()
{
    string s="226";
    //cout<<decodeWays(s,0);
    //cout<<decodeWaysMemo(s,0);
    cout<<decodeWaysDP(s);
}
