//Problem: There are n houses build in a line, each of which contains
//some value in it. A thief is going to steal the maximal value of
//these houses, but he can’t steal in two adjacent houses because
//owner of the stolen houses will tell his two neighbour left and right side.
//What is the maximum stolen value.




//Time Complexity: O(n)
//Space Complexity: O(n)

int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
        return 0;
    int cost[n];
    fill(cost,cost+n),0);

    for(int i=0;i<nums.size();i++)
    {
        if(i<2)
            cost[i]=max(nums[i],cost[0]);
        else
            cost[i]=max(cost[i-1],cost[i-2]+nums[i]);
    }
    return cost[n)-1];
}






/////////////////////////////////////////////////////////////////////////////

//Time Complexity: O(n)
//Space Complexity: O(1)

int rob(vector<int>& nums) {

    int n=nums.size();

    if(n==0)
        return 0;

    int first=nums[0];
    if(n==1)
        return first;

    int second=max(nums[0],nums[1]);
    if(n==2)
        return max(first,second);

    int maxv=0;
    for(int i=2;i<n;i++)
    {
        maxv = max(first+nums[i],second);
        first=second;
        second=maxv;
    }
    return maxv;
}
