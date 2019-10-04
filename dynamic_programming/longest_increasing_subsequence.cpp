//The Longest Increasing Subsequence (LIS) problem is to find the length
//of the longest subsequence of a given sequence such that all elements of the
//subsequence are sorted in increasing order.
//Time Complexity: O(n^2)
//Space Complexity: O(n)

/*PS: The only difference between LIS and LNDS (Longest Non-Decreasing Subsequence) is one change.
We change "nums[i] > nums[j]" to "nums[i] >= nums[j]"*/


#include<bits/stdc++.h>
using namespace std;

int lis(int a[],int n)
{
    int maxSoFar=1;
    vector<int> maxlen(n,1);

    //store the LIS till i in maxlen[i]
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
                maxlen[i] = max(maxlen[i],maxlen[j]+1);
        }
        maxSoFar=max(maxSoFar,maxlen[i]);
    }
    return maxSoFar;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The length of maximum increasing subsequence is: "<<lis(arr, n);
    return 0;
}
