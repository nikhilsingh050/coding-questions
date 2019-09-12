#include<bits/stdc++.h>
using namespace std;

int cutRod(int a[],int length,int memo[])
{
    if(length<=0)
        return 0;

    if(memo[length]==0)
    {
        //cout<<"Calculated the value!"<<endl;
        int m=INT_MIN;
        for(int i=1;i<=length;i++)
            m=max(m,a[i-1]+ cutRod(a,length-i,memo));
        memo[length]=m;
    }
    //else cout<<"Result found in memo!"<<endl;

    return memo[length];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int memo[size+1]={0};
    cout<<"Maximum Obtainable Value is: "<<cutRod(arr, size,memo);
    return 0;
}

