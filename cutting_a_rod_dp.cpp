#include<bits/stdc++.h>
using namespace std;

int cutRod(int a[],int length)
{
    int memo[length+1]={0};

    for(int i=1;i<=length;i++)
    {
        int maxv=INT_MIN;
        for(int j=1;j<=i;j++)
            maxv=max(maxv, a[j-1]+memo[i-j]);
        memo[i]=maxv;
    }

    return memo[length];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum Obtainable Value is: "<<cutRod(arr, size);
    return 0;
}
