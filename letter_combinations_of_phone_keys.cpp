//return all possible letter combinations that the number could represent.
//keys of old nokia phones

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(string digits, int  pos, vector<string> letter, string& path,vector<string>& result)
{
    if(pos==digits.length())
    {
        result.push_back(path);
        return;
    }

    for(char c: letter[digits[pos]-'0'])
    {
        path+=c;
        dfs(digits, pos+1, letter, path, result);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> result;
    if(digits.length()==0)
        return result;

    vector<string> letter = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string path="";
    dfs(digits,0,letter,path,result);
    return result;
}

int main()
{
    string digits="23";
    vector<string> result = letterCombinations(digits);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}