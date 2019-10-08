//IP address decompositions of a string
//(https://leetcode.com/problems/restore-ip-addresses/)

//Backtracking Problem

//Time Complexity: O(3^4) -> O(1)           :3 choices, maximum height of recursion tree is 4
//Space Complexity: O(3^4) -> O(1)          :3^4 ip addresss can be stored in result
//(i guess)



#include<bits/stdc++.h>
using namespace std;



void restoreIP(int n, int parts, string s, vector<string> &path, vector<string> &result)
{
    //base case ->> our goal -> add ip address to result and return
    if(n==s.length() && parts==4)
    {
        string ip="";
        //convert parts to ip address and add to result
        for(int i=0;i<path.size();i++)
        {
            ip+=path[i];
            if(i<path.size()-1)
                ip+='.';
        }
        result.push_back(ip);
        return;
    }

    //base case
    if(parts>=4)
        return;

    //check all the possible parts starting with nth index till length 3
    for(int i=n; i<n+3 && n<s.length(); i++)
    {
        string tempString = s.substr(n,i-n+1);
        int tempInt = atoi(tempString.c_str());

        //there cannot be preceding zeros if length>2
        if(tempString.length()>1 && tempString[0]=='0')
            continue;

        //if part is valid -> add to path
        if(tempInt>=0 && tempInt<256)
        {
            path.push_back(tempString);
            restoreIP(i+1,parts+1,s,path,result);
            path.pop_back();            //backtrack
        }
    }
}



vector<string> restoreIpAddresses(string s)
{
    vector<string> result;
    vector<string> path;
    restoreIP(0,0,s,path,result);
    return result;
}



int main()
{
    string s="25525511135";
    vector<string> result;
    result=restoreIpAddresses(s);

    for(string a:result)
        cout<<a<<endl;
}
