//Comparator is a function that is used to compare two value.
//STL sorted container have a comparator less<> by default which sorts them is ascending order.
//greater<> can be used explicitly to sort a container is descending order.
//example: set<int,greater<int>> s;

//NOTE: Comparator needs to be defined for user created data types.

//sort() function also require custom comparator for sorting of user defined data types.

///////////////////////////////////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;



//1. Comparator for the data type using member operator:

struct myData
{
    int value;
    myData(int value)
    {
        this->value=value;
    }

    //member operator as comparator
    bool operator<(const myData &b)
    const{
        return this->value < b.value;
    }
};


///////////////////////////////////////////////////////////////////////////////////////////////////

//2. Function object as comparison function:

//Custom Comparator
struct comp
{
    bool operator()(const myData &lhs, const myData &rhs) const{
        return lhs.value<rhs.value;
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////////

void print_set(set<myData,comp> &s)
{
    for(auto itr = s.begin(); itr!=s.end();itr++)
        cout<<(*itr).value<<" ";
    cout<<endl;
}

void print_set(set<myData> &s)
{
    for(auto itr = s.begin(); itr!=s.end();itr++)
        cout<<(*itr).value<<" ";
    cout<<endl;
}

void print_vector(vector<myData> &v)
{
    for(auto itr = v.begin(); itr!=v.end();itr++)
        cout<<(*itr).value<<" ";
    cout<<endl;
}


/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //1. uses member operator:
    set<myData> s;

    //2. uses custom comparator as function object:
    //set<myData,comp> s;

    s.insert(myData(10));
    s.insert(myData(50));
    s.insert(myData(40));
    s.insert(myData(30));
    s.insert(myData(20));

    print_set(s);           //Output: 10 20 30 40 50

    vector<myData> v;
    v.push_back(myData(50));
    v.push_back(myData(10));
    v.push_back(myData(30));
    v.push_back(myData(20));
    v.push_back(myData(40));

    //1. uses member operator:
    sort(v.begin(),v.end());

    //2. uses custom comparator as function object:
    //sort(v.begin(),v.end(),comp());

    print_vector(v);        //Output: 10 20 30 40 50
}
