//Print Pattern
/*
for n=5

1*2*3*4*5
11*12*13*14*15
21*22*23*24*25
16*17*18*19*20
6*7*8*9*10
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int num=1;
    int a[n][n];

    int start=0,end=n-1,row=start;
    bool turn=true;
    while(num<n*n)
    {
        if(turn)
        {
            row=start;
            start++;
        }
        else
        {
            row=end;
            end--;
        }

        for(int j=0;j<n;j++)
        {
            a[row][j]=num;
            num++;
        }
        turn=!turn;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j];
            if(j<n-1)
            cout<<"*";
        }
        cout<<endl;
    }
}


