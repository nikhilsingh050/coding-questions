#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> us;
    int i=0,j=0,m=0,n;
    n=s.length();
    while(i<n && j<n)
    {
        if(us.find(s[j])==us.end())
        {
            us.insert(s[j]);
            j++;
            m=max(m,j-i);
        }
        else
        {
            us.erase(s[i]);
            i++;
        }
    }
    return m;
}

int main()
{
    string s="abagfjsgdhjjskds";
    cout<<lengthOfLongestSubstring(s);
    return 0;
}
