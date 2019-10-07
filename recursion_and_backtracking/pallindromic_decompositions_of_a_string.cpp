//Print all palindromic decompositions of a string.
//(https://leetcode.com/problems/palindrome-partitioning/)

//Backtracking

//Time complexity: O(n * 2^n)
//Space complexity: O(n)


#include<bits/stdc++.h>
using namespace std;



//check if the substring is pallindrome
bool isPalindrome(int left, int right, string s)
{
    while(left<right)
    {
        if(s[left]!=s[right])
            return false;

        left++;
        right--;
    }
    return true;
}



void decomposeString(int n, string s, vector<string> &currentPath)
{
    if(n==s.length())
    {
        for(int j=0;j<currentPath.size();j++)
            cout<<currentPath[j]<<" ";
        cout<<endl;

        return;
    }

    //check all the strings starting from n till the end of the string
    //n to n , n to n+1, n to n+2, n to s.end()
    for(int i=n;i<s.length();i++)
    {
        if(isPalindrome(n,i,s))
        {
            currentPath.push_back(s.substr(n,i-n+1));

            //call for rest of the string
            decomposeString(i+1,s,currentPath);

            //backtrack
            currentPath.pop_back();
        }
    }
}



void partition(string s)
{
    vector<string> currentPath;
    decomposeString(0,s,currentPath);
}



int main()
{
    string s="poop";
    partition(s);
}
