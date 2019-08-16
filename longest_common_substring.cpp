#include<iostream>
using namespace std;

int main()
{
    string x="zaxabcjjedek";
    string y="zsabc";

    int max=0,row,col;

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
            {
                l[i][j]=l[i-1][j-1] + 1;
                if(l[i][j]>max)
                {
                    max=l[i][j];
                    row=i;
                    col=j;
                }
            }
            else
                l[i][j]=0;
        }
    }
    cout<<"maximum length of substring: "<<max<<endl;

    char substring[max];
    while(l[row][col]!=0)
    {
        substring[--max]=x[row-1];
        row--;
        col--;
    }
    cout<<substring;
    return 0;
}
