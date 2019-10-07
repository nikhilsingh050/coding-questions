//Generate all the valid parenthesis combination for n opening and closing parenthesis.

//Recursive Approach:

//Two Possible paths:
//1. Add opening parenthesis (cannot be greater than n)
//2. Add closing parenthesis (cannot be less than opening parenthesis)


#include<bits/stdc++.h>
using namespace std;


void findValidParen(int opening, int closing, string &path, vector<string> &result)
{
    //base case
    if(closing==0 && opening==0)
    {
        result.push_back(path);
        return;
    }

    //there should be remaining opening parenthesis
    if(opening>0)
    {
        path+='(';
        findValidParen(opening-1,closing,path,result);
        path.pop_back();                //backtrack
    }

    //remaining closing parenthesis should be greater than remaining opening parenthesis
    if(opening<closing)
    {
        path+=')';
        findValidParen(opening,closing-1,path,result);
        path.pop_back();                //backtrack
    }
}




//////////////////////////////////////////////////////////////////////////////////////////////

//Simplified Version:
//Automatic backtracking -> call by value

void findValidParen(int opening, int closing, string path, vector<string> &result)
{
    //base case
    if(closing==0 && opening==0)
    {
        result.push_back(path);
        return;
    }

    if(opening>0)
        findValidParen(opening-1,closing,path+'(',result);

    if(opening<closing)
        findValidParen(opening,closing-1,path+')',result);
}


vector<string> generateParenthesis(int n)
{
    vector<string> result;
    string path="";
    findValidParen(n,n,path,result);
    return result;
}

int main()
{
    int n=3;
    vector<string> result;
    result=generateParenthesis(n);
    cout<<"Valid Parenthesis combinations: "<<endl;
    for(string s: result)
        cout<<s<<endl;
}
