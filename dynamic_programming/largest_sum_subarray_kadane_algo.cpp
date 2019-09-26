#include<bits/stdc++.h>
using namespace std;

//Kadane's Algorithm
//start from second element and check which is better ->
//extending the previous subarray or starting a new subarray from current position.

int maxSubArray(vector<int>& nums)
{
    int last_max=nums[0];
    int maxx=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        last_max=max(nums[i]+last_max,nums[i]);

        maxx= max(maxx,last_max);
    }
    return maxx;
}

int main()
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums);
    return 0;
}
