//Print all possible strings of length k that can be formed from a set of n characters.
#include<bits/stdc++.h>
using namespace std;

void printPerms(string s, int k,string path)
{
    if(k<=0)
    {
        cout<<path<<endl;
        return;
    }

    for(char c:s)
    {
        path+=c;
        printPerms(s,k-1,path);
        path.pop_back();
    }
}

int main()
{
    string s="abc";
    int k=3;
    string path="";
    printPerms(s,k,path);
}
