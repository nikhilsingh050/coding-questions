//minimum distance to reach the boundary of a grid from a source

#include<bits/stdc++.h>
using namespace std;

#define row 5
#define col 5

int minDistance[row][col], isVisited[row][col];

//function to check if a move is valid
bool isValid(int grid[row][col], int i, int j)
{
    if(i<0 || i>row-1 || j<0 || j> col-1 || isVisited[i][j] || grid[i][j])
        return false;
    else
        return true;
}

//function to find the minimum distance of boundary from source
int findMinPathminDistance(int grid[row][col] , int sourceRow, int sourceCol)
{
    queue<pair<int,int> > q;

    //when source is on the boundary
    if(sourceRow==0 || sourceCol==0 || sourceRow==row-1 || sourceCol==col-1)
        return 0;

    //initialize minimum distance and min distance grid
    int minD = row*col;

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            minDistance[i][j]=row*col;

    //now start from source
    //enqueue source
    q.push(make_pair(sourceRow, sourceCol));

    minDistance[sourceRow][sourceCol]=0;

    isVisited[sourceRow][sourceCol]=1;

    //use front of queue as current cell and evaluate all possible unit movements
    //then pop out the current cell
    while(!q.empty())
    {
        //front element of the queue will be our current element
        int currentRow = q.front().first;
        int currentCol = q.front().second;

        //move down
        if(isValid(grid, currentRow+1, currentCol))
        {
            q.push(make_pair(currentRow+1, currentCol));
            minDistance[currentRow+1][currentCol]=min(minDistance[currentRow+1][currentCol], minDistance[currentRow][currentCol]+1);
            isVisited[currentRow+1][currentCol]=1;
        }

        //move up
        if(isValid(grid, currentRow-1, currentCol))
        {
            q.push(make_pair(currentRow-1,currentCol));
            minDistance[currentRow-1][currentCol]= min(minDistance[currentRow-1][currentCol],minDistance[currentRow][currentCol]+1);
            isVisited[currentRow-1][currentCol]=1;
        }

        //move left
        if(isValid(grid, currentRow, currentCol-1))
        {
            q.push(make_pair(currentRow,currentCol-1));
            minDistance[currentRow][currentCol-1]= min(minDistance[currentRow][currentCol-1],minDistance[currentRow][currentCol]+1);
            isVisited[currentRow][currentCol-1]=1;
        }

        //move right
        if(isValid(grid, currentRow-1, currentCol))
        {
            q.push(make_pair(currentRow,currentCol+1));
            minDistance[currentRow][currentCol+1]= min(minDistance[currentRow][currentCol+1],minDistance[currentRow][currentCol]+1);
            isVisited[currentRow][currentCol+1]=1;
        }

        q.pop();
    }

    //check the minimum value at boundary cells

    //left boundary
    for(int i=0;i<row;i++)
        minD= min(minD, minDistance[i][0]);

    //right boundary
    for(int i=0;i<row;i++)
        minD = min(minD, minDistance[i][col-1]);

    //top boundary
    for(int i=0;i<col;i++)
        minD=min(minD, minDistance[0][i]);

    //bottom boundary
    for(int i=0; i<col;i++)
        minD = min(minD, minDistance[row-1][i]);

    return minD;
}

int main()
{
    int sourceRow = 1, sourceCol = 3;
    int grid[row][col] = { 1, 1, 1, 1, 0,
                           0, 0, 1, 0, 1,
                           0, 0, 1, 0, 1,
                           1, 0, 0, 0, 1,
                           1, 1, 0, 1, 0 };

    cout << findMinPathminDistance(grid, sourceRow, sourceCol);
    return 0;
}
