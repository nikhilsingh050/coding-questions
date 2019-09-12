//Print all K length words that can be formed from given characters without repetition.
#include<bits/stdc++.h>
using namespace std;

//O(n) search in string
void printPerms(string s, int k,string path)
{
    if(k<=0)
    {
        cout<<path<<endl;
        return;
    }

    for(char c:s)
    {
        if(find(path.begin(),path.end(),c)==path.end())
        {
            path+=c;
            printPerms(s,k-1,path);
            path.pop_back();
        }
    }
}

int main()
{
    string s="abc";
    int k=3;
    string path="";
    printPerms(s,k,path);
}

//-----------------------------------------------------------------------

//O(1) search in unordered_set
void printPerms(string s, int k,string path,unordered_set<char> set)
{
    if(k<=0)
    {
        cout<<path<<endl;
        return;
    }

    for(char c:s)
    {
        if(set.find(c)==set.end())
        {
            path+=c;
            set.insert(c);
            printPerms(s,k-1,path,set);
            path.pop_back();
            set.erase(c);
        }
    }
}

int main()
{
    string s="abc";
    int k=3;
    string path="";
    unordered_set<char> set;
    printPerms(s,k,path,set);
}

