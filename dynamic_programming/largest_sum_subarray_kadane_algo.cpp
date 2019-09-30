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


//Find the index of maximum subarray:
//keep track of current subarray index
//whenever a maximum length is found -> update max start and end.
void maxSubArrayIndex(vector<int>& a)
{
    int last_max=a[0],maxx=a[0],start=0,end=0,mstart=0,mend=0;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]>a[i]+last_max)
        {
            last_max=a[i];
            start=i;
            end=i;
        }
        else
        {
            last_max=a[i]+last_max;
            end=i;
        }

        if(maxx<last_max)
        {
            maxx=last_max;
            mstart=start;
            mend=end;
        }
    }
    cout<<"Maximum subarray index: "<<mstart<<" : "<<mend;
}

int main()
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Maximum subaarray length: "<<maxSubArray(nums)<<endl;
    maxSubArrayIndex(nums);
    return 0;
}
