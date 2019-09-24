//Print all K length words that can be formed from given characters without repetition.
#include<bits/stdc++.h>
using namespace std;

void printPerms(string s, int k,string path, bool visited[])
{
    if(k<=0)
    {
        cout<<path<<endl;
        return;
    }

    for(int i=0;i<s.length();i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            printPerms(s,k-1,path+s[i],visited);
            visited[i]=false;
        }
    }
}

int main()
{
    string s="abc";
    int k=3;
    string path="";
    int n=s.length();
    bool visited[n]={false};
    printPerms(s,k,path,visited);
}
