//Custom Comparator for stl containers and sorting:

//Comparator is a function that is used to compare two value.
//STL sorted container have a comparator less<> by default which sorts them is ascending order.
//greater<> can be used explicitly to sort a container is descending order.
//example: set<int,greater<int>> s;

//NOTE: Comparator needs to be defined for user created data types.

//sort() function also require custom comparator for sorting of user defined data types.


#include<bits/stdc++.h>
using namespace std;

struct myData
{
    int value;
    myData(int value)
    {
        this->value=value;
    }

};

//Custom Comparator
struct comp
{
    bool operator()(const myData &lhs, const myData &rhs) const{
        return lhs.value<rhs.value;
    }
};

void print_set(set<myData,comp> &s)
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

int main()
{
    set<myData,comp> s;

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

    sort(v.begin(),v.end(),comp());

    print_vector(v);        //Output: 10 20 30 40 50
}
