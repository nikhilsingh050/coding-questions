//Complexity: O(n)

/*Initialize a variable curr_sum as first element. curr_sum indicates the sum of current
subarray. Start from the second element and add all elements one by one to the curr_sum.
If curr_sum becomes equal to sum, then print the solution. If curr_sum exceeds the sum,
then remove trailing elements while curr_sum is greater than sum. */


#include<bits/stdc++.h>
using namespace std;

void subArraySum(int a[], int n, int sum)
{
    int curr_sum = a[0];
    int start=0;

    //start from second element
    for(int i=1;i<n;i++)
    {
        //remove starting elements of the window if it gets greater than given sum
        while(curr_sum > sum && start<i-1)
        {
            curr_sum-=a[start];
            start++;
        }

        //found
        if(curr_sum ==sum)
        {
            cout<<"Subarray between: "<<start<<" & "<<i-1;
            return;
        }

        //add next element to the window
        //if(i<n) : no use maybe
        curr_sum+=a[i];
    }

    cout<<"Not found!!!";
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}
