//Given an integer array, find number of ways to calculate a target number using
//only array elements and addition or subtraction operator.

#include<bits/stdc++.h>
using namespace std;

int findWays(vector<int> a, int i, int target)
{
    if(target!=0 && i>=a.size())
        return 0;
    if(target==0)
        return 1;

    int count;
    count = findWays(a,i+1,target) + findWays(a,i+1,target-a[i]) + findWays(a,i+1,target+a[i]);
    return count;
}

int main()
{
    vector<int> arr = {-3, 1, 3, 5, 7};
    int k = 6;
    cout << findWays(arr, 0, k) << endl;
    return 0;
}
