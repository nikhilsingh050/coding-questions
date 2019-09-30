/*
The Key To This Problem:

For every leftBorderIndex and rightBorderIndex of the POSSIBLE maximal rectangle,
we want to know the largest sum we can yield VERTICALLY so that we can
deduce the best topBorderIndex and bottomBorderIndex.

This is why we keep the array of running sums for each row. We are interested
in best vertical value to start and end at (at each attempt of all of the
combinations of leftBorderIndex and rightBorderIndex values).
*/

//Time Complexity: O(col*col*row)
//Space Complexity: O(row)

#include<bits/stdc++.h>
using namespace std;


struct Rectangle
{
    int interiorSum=INT_MIN;
    int leftBorderIndex;
    int rightBorderIndex;
    int topBorderIndex;
    int bottomBorderIndex;
};

struct KadaneResult
{
    int maxSum;
    int startIndex;
    int endIndex;
};




//find the maximum sub-array in running sum array.
//return the object of KadaneResult containing maxSum and start and end index.
KadaneResult kadane(vector<int> a)
{
    int maxx=a[0],last_max=a[0],start=0,end=0,mstart=0,mend=0;

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
        if(last_max>maxx)
        {
            maxx=last_max;
            mstart=start;
            mend=end;
        }
    }

    KadaneResult kadaneResult;
    kadaneResult.maxSum = maxx;
    kadaneResult.startIndex = mstart;
    kadaneResult.endIndex = mend;

    return kadaneResult;
}




void findMaxSum(vector<vector<int>> matrix, int rows, int cols)
{
    //store sum of elements in each row (between current left and right index).
    vector<int> runningRowsSum(rows);

    Rectangle maxRect;

    for(int left=0; left<cols; left++)
    {
        //We will reset the running row sums all to 0 since
        //this is a new planting of the left bound
        for (int i = 0; i < rows; i++)
            runningRowsSum[i] = 0;


        for(int right=left; right<cols; right++)
        {
            //update sum for new column added
            for (int i = 0; i < rows; i++)
                runningRowsSum[i] += matrix[i][right];

            //kadane function will return the max sum and indexes.
            KadaneResult kadaneResult = kadane(runningRowsSum);

            if(kadaneResult.maxSum > maxRect.interiorSum)
            {
                maxRect.interiorSum = kadaneResult.maxSum;

                maxRect.leftBorderIndex = left;
                maxRect.rightBorderIndex = right;

                maxRect.topBorderIndex = kadaneResult.startIndex;
                maxRect.bottomBorderIndex = kadaneResult.endIndex;
            }
        }
    }

    cout<<"max sum: "<<maxRect.interiorSum<<endl;
    cout<<"left corner: "<<maxRect.topBorderIndex<<" , "<<maxRect.leftBorderIndex<<endl;
    cout<<"right corner: "<<maxRect.bottomBorderIndex<<" , "<<maxRect.rightBorderIndex<<endl;
}




int main()
{
    int row=4,col=5;
    vector<vector<int>> matrix = {{1, 2, -1, -4, -20},
                                  {-8, -3, 4, 2, 1},
                                  {3, 8, 10, 1, 3},
                                  {-4, -1, 1, 7, -6}};

    findMaxSum(matrix,row,col);
    return 0;
}
