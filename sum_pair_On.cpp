//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// time: O(n)
// space: O(n)
#include<bits/stdc++.h>
using namespace std;

vector<int> sumpair(vector<int> &nums, int sum)
{
    /*unordered_map is faster than map

    map: sorted, uses BST implementation, O(logn)
    unordered map: uses hash table, Average: O(1)
    */

    unordered_map<int,int> m; //key -> vector element, value-> index
    vector<int> result;
    for(int i=0;i<nums.size();i++)
    {
        unordered_map<int,int>::iterator temp = m.find(sum-nums[i]);

        //m.find() returns m.end() if element is not found

        if(temp != m.end())
        {
            result.push_back(temp->second);
            result.push_back(i);
        }
        m[nums[i]]=i; //m[key] = value
    }
    return result;
}
int main()
{
    int a[] = {2,7,11,15};
    int n= sizeof(a)/sizeof(a[0]);
    vector<int> v(a, a+n);
    int sum=9;

    vector<int> result = sumpair(v, sum);

    cout<<"["<<result[0]<<","<<result[1]<<"]";
    return 0;
}
