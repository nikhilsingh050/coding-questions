#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string x="abcd";
    string y="ahjbjjchhjd";

    int m=x.length();
    int n=y.length();

    int l[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                l[i][j]=0;
            else if(x[i-1]==y[j-1])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    }
    cout<<"length: "<<l[m][n]<<endl;

    //printing subsequence
    int len= l[m][n];
    int i=m,j=n;
    char subsequence[len];

    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            subsequence[--len]=x[i-1];
            i--;
            j--;
        }
        else if(l[i-1][j]>l[i][j-1])
            i--;
        else
            j--;
    }
    cout<<subsequence;
}
