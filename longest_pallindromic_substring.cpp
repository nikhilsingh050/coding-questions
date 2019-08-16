//Print longest pallindromic SUBSTRING of a given string
#include<bits/stdc++.h>
using namespace std;

string lps(string s)
{
    int n=s.length();
    if(n==0) return "";

    //table to store if window [i to j] is pallindrome or not
    bool l[n][n] ={false};

    //string of length 1 are all pallindromes
    for(int i=0;i<n;i++)
        l[i][i]=true;

    int row=0,maxlen=1;

    //for window length 2 and greater
    for(int len=2; len<=n; len++)
    {
        for(int i=0;i<n-len+1;i++)
        {
            int j=i+len-1;

            //for length 2
            if(s[i]==s[j] && len==2)
            {
                l[i][j]=true;
                if(len > maxlen)
                {
                    maxlen =len;
                    row=i;
                }
            }

            //for length greater than 2
            else if(s[i]==s[j] && l[i+1][j-1]==true)
            {
                l[i][j]=true;
                if(len>maxlen)
                {
                    maxlen=len;
                    row=i;
                }
            }
        }
    }
    cout<<"Length of longest pallindromic string: "<<maxlen<<endl;
    string pallindrome= s.substr(row,maxlen);
    return pallindrome;
}

int main()
{
    string s="abcdabcbadbcda";
    cout<<lps(s);
    return 0;
}
