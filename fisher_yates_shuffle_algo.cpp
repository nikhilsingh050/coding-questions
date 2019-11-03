//Fisher Yates Algorithms: Keep replacing last element with random index elements.

#include<bits/stdc++.h>
using namespace std;

void randomize(int a[], int n)
{
    srand(time(0));

    for(int i=n-1;i>0;i--)
    {
        int j = rand()%(i+1);
        swap(a[i],a[j]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Original Array: ";
    for(int i:arr)
        cout<<i<<" ";

    randomize (arr, n);

    cout<<"\n\nShuffled array: ";
    for(int i:arr)
        cout<<i<<" ";
    return 0;
}
