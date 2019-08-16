//sieve of eratosthenes
//sexy prime: prime numbers having difference 6
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    bool prime[n+1];

    memset(prime,true,sizeof(prime));

    for(int p=2;p*p<=n;p++)
    {
        if(prime[p])
        {
            for(int i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }

    for(int i=2;i<=n-6;i++)
    {
        if(prime[i] && prime[i+6])
            cout<<"("<<i<<","<<i+6<<") "<<endl;
    }
    return 0;
}
