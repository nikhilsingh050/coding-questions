#include <bits/stdc++.h>
using namespace std;
#define N 8

//possible moves
int rowMove[] = {2,1,-1,-2,-2,-1,1,2};
int colMove[] = {1,2,2,1,-1,-2,-2,-1};


void printBoard(const vector<vector<int>> &visited)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0;j<N;j++)
            cout<<visited[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}


//check if the given move is valid
bool isValid(const vector<vector<int>> &visited,int row, int col)
{
    return (row>=0 && row<N && col>=0 && col<N && visited[row][col]==0);
}


bool solveKnight(vector<vector<int>> &visited,int row, int col,int move)
{
    //printBoard(visited);
    if(move==N*N)
    {
        printBoard(visited);
        return true;
    }

    for(int i=0;i<N;i++)
    {
        int newRow = row + rowMove[i];
        int newCol = col + colMove[i];

        if(isValid(visited,newRow,newCol))
        {
            move++;
            visited[newRow][newCol] = move;
            if(solveKnight(visited,newRow,newCol,move))
                return true;
            move--;
            visited[newRow][newCol]=0;
        }
    }
    return false;
}


int main()
{
    vector<vector<int>> visited(N,vector<int>(N,0));
    visited[0][0]=1;
    if(!solveKnight(visited,0,0,1))
        cout<<"not possible";
    return 0;
}
