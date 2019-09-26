#include<bits/stdc++.h>
using namespace std;


//Recursive Solution:
//Start from last chars of both the strings
//if both char are same add 1 to result and remove both the chars
//else -> result is max of (removing last char from x, removing last char from y)

int lcsUtil(string x, string y, int m, int n)
{
    if(m==0 || n==0)
        return 0;

    int res;
    if(x[m-1]==y[n-1])
        res = 1 + lcsUtil(x,y,m-1,n-1);
    else
        res = max(lcsUtil(x,y,m-1,n), lcsUtil(x,y,m,n-1));

    return res;
}

int lcs(string x, string y)
{
    int m=x.length();
    int n=y.length();

    return lcsUtil(x,y,m,n);
}




///////////////////////////////////////////////////////////////////////

//Dynamic Programming Solution:

void printLCS(vector<vector<int>> &memo,int len,string x, string y);

int lcs(string x, string y)
{
    int m=x.length();
    int n=y.length();

    int memo[m+1][n+1];     //+1 for empty string case
    //vector<vector<int>> memo(m+1,vector<int>(n+1));

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            //for base cases -> in case of comparison with empty strings
            if(i==0 || j==0)
                memo[i][j]=0;

            //when current chars are same -> result = 1 + result without including these chars
            else if(x[i-1]==y[j-1])
                memo[i][j] = 1+memo[i-1][j-1];

            //max of (removing current char from x, removing current char from x)
            else
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
        }
    }

    printLCS(memo, memo[m][n],x,y);
    return memo[m][n];
}


//print the LCS
void printLCS(vector<vector<int>> &memo,int len,string x, string y)
{
    int i=x.length();
    int j=y.length();
    string result(len,' ');

    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            result[--len] = x[i-1];
            i--;
            j--;
        }
        else if(memo[i-1][j] > memo[i][j-1])
            i--;
        else
            j--;
    }
    cout<<"Longest common subsequence is: "<<result<<endl;
}


int main()
{
    string x="abcd";
    string y="ahjbjjchhjd";
    cout<<"Length of longest common subsequence is: "<<lcs(x,y);
    return 0;
}
