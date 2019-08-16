//Print longest pallindromic subsequence
#include<iostream>
using namespace std;

int lps(string s)
{
    int n=s.length();

    if(n==0)
        return 0;

    //table to store length of longest pallindromic subsequence in window [i to j]
    int l[n][n]={0};

    //strings of length 1 are pallindromes of length 1
    for(int i=0;i<n;i++)
        l[i][i]=1;

    int maxlen=1;

    //for window length 2 and greater
    for(int len=2;len<=n;len++)
    {
        for(int i=0; i<n-len+1;i++)
        {
            int j=i+len-1;

            //for window length 2
            if(s[i]==s[j] && len==2)
            {
                l[i][j]=2;
                maxlen=max(maxlen,l[i][j]);
            }
            //window length greater than 2
            else if(s[i]==s[j])
            {
                l[i][j]=l[i+1][j-1]+2;
                maxlen=max(maxlen,l[i][j]);
            }
            else
            {
                l[i][j]=max(l[i][j-1],l[i+1][j]);
                maxlen= max(maxlen,l[i][j]);
            }
        }
    }
    return maxlen;  //or return l[0][n-1];
}

int main()
{
    string s="abcdabcbadbcda";
    cout<<lps(s);
    return 0;
}
