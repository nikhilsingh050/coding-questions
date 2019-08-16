//print longest palindromic subsequence
//using longest common subsequence
//lcs of given string and reverse of it
#include<bits/stdc++.h>
using namespace std;

void lcs(string x, string y)
{
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
    int len=l[m][n];
    char seq[len+1];
    seq[len]='\0';

    int i=m,j=n;

    //printing subsequence
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            seq[--len]=x[i-1];
            i--;
            j--;
        }
        else if(l[i-1][j]>l[i][j-1])
            i--;
        else
            j--;
    }
    cout<<seq;
}

void lps(string s)
{
    string x,y,result;
    x=s;
    y=s;
    reverse(y.begin(),y.end());
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    lcs(x,y);
}

int main()
{
    string s="sdjaljlksa";
    lps(s);
    return 0;
}
