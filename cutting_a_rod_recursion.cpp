/*Given a rod of length n inches and an array of prices that contains
prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.
For example, if length of the rod is 8 and the values of different pieces are given as following,
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

length   | 1   2   3   4   5   6   7   8
--------------------------------------------
price    | 1   5   8   9  10  17  17  20    */


#include<bits/stdc++.h>
using namespace std;

int cutRod(int price[], int length)
{
   if (length <= 0)
     return 0;

   int maxValue= INT_MIN;

   for (int i = 1; i<=length; i++)
         maxValue = max(maxValue, price[i-1] + cutRod(price, length-i));

   return maxValue;
}

int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int length = sizeof(price)/sizeof(price[0]);
    cout<<"Maximum profit: "<<cutRod(price,length);
    return 0;
}
