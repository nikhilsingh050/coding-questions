//Print all possible paths to reach the bottom right corner from top left corner
//Rat can move left,right,up,down.
#include<bits/stdc++.h>
using namespace std;

void printMaze(vector<vector<int>> result,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<result[i][j];
        cout<<endl;
    }
    cout<<endl;
}

void findPaths(vector<vector<int>> maze,vector<vector<int>> &result,int n, int x,int y)
{
    if(x==n-1 && y==n-1)
    {
        result[x][y]=1;
        printMaze(result,n);
        return;
    }

    if(x<0 || x>=n || y<0 || y>=n || maze[x][y]==0 || result[x][y]==1)
        return;

    result[x][y]=1;
    findPaths(maze,result,n,x-1,y);
    findPaths(maze,result,n,x+1,y);
    findPaths(maze,result,n,x,y-1);
    findPaths(maze,result,n,x,y+1);
    result[x][y]=0;
}
void solveMaze(vector<vector<int>> maze,int n)
{
    /*vector<vector<int>> result= { { 0, 0, 0 },
                     { 0, 0, 0 },
                     { 0, 0, 0 }};*/

    vector<vector<int>> result;
    for(int i=0;i<n;i++)
    {
        vector<int> v;
        for(int j=0;j<n;j++)
        {
            v.push_back(0);
        }
        result.push_back(v);
    }
    findPaths(maze,result,n,0,0);
}

int main()
{
    vector<vector<int>> maze = { { 1, 0, 1},
                                 { 1, 1, 1},
                                 { 1, 1, 1} };

    solveMaze(maze,3);
    return 0;
}

