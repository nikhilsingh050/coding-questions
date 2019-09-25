#include<bits/stdc++.h>
using namespace std;

//possible moves i.e., R,L,U,D
int moveRow[] = {0,0,1,-1};
int moveCol[] = {1,-1,0,0};
int moves=4;


void printPath(vector<vector<int>> result,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<result[i][j];
        cout<<endl;
    }
    cout<<endl;
}

bool isValidMove(vector<vector<int>> maze,int n,vector<vector<int>> visited,int row,int col)
{
    if(row>=0 && row<n && col>=0 && col<n && visited[row][col]==0 && maze[row][col]==1)
        return true;
    return false;
}

void findAllPaths(vector<vector<int>> maze,int n,int row,int col,int desRow,int desCol,vector<vector<int>> visited)
{
    if(row==desRow && col==desCol)
    {
        printPath(visited,n);
        return;
    }

    for(int i=0;i<moves;i++)
    {
        int newRow = row + moveRow[i];
        int newCol = col + moveCol[i];

        if(isValidMove(maze,n,visited,newRow,newCol))
        {
            visited[newRow][newCol]=1;
            findAllPaths(maze,n,newRow,newCol,desRow,desCol,visited);
            visited[newRow][newCol]=0;
        }
    }
}
void solveMaze(vector<vector<int>> maze,int n,int row, int col,int desRow,int desCol)
{
    vector<vector<int>> visited(n,vector<int>(n,0));
    visited[row][col]=1;
    findAllPaths(maze,n,row,col,desRow,desCol,visited);
}

int main()
{
    vector<vector<int>> maze = { { 1, 0, 1},
                                 { 1, 1, 1},
                                 { 1, 1, 1} };

    int cRow=0, cCol=0, desRow=2, desCol=2;
    solveMaze(maze,3,cRow,cCol,desRow,desCol);
    return 0;
}
