#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num)
{
    vector<pair<int,string>> m = {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};

    auto itr = m.begin();

    string result="";

    while(num>0 && itr!=m.end())
    {
        if(num>=itr->first)
        {
            num-=itr->first;
            result+=itr->second;
        }

        else
            itr++;
    }
    return result;
}

int main()
{
    int n=745;
    cout<<intToRoman(n);
    return 0;
}
