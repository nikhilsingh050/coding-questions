//n Queen Problem:    ("problem? problem ye hai ki wo ladki hai.. aur kya problem hai.........")
//The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens
//attack each other.
//Only one queen can be placed in each row.

#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<bool>> &board,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

//check if the queen will be safe in the given position
bool isValid(vector<vector<bool>> &board,int size,int row,int col)
{
    bool valid=true;
    //check if a queen exists in the same column
    for(int i=0;i<size;i++)
    {
        if(board[i][col])
            valid=false;
    }

    //check if queen exists in NW direction -> no need to check below the row
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            valid=false;
    }

    //check if queen exists in NE direction -> no need to check below the row
    for(int i=row,j=col;i>=0 && j<size;i--,j++)
    {
        if(board[i][j])
            valid=false;
    }
    return valid;
}


bool nQueen(vector<vector<bool>> &board, int size, int row)
{
    if(row>=size)
    {
        printBoard(board,size);
        return true;
    }

    //try putting queen in each column in current row
    for(int col=0;col<size;col++)
    {
        if(isValid(board,size,row,col))
        {
            board[row][col]=true;
            if(nQueen(board,size,row+1))
                return true;
            board[row][col]=false;
        }
    }
    return false;
}

int main()
{
    int size=8;
    vector<vector<bool>> board(size,vector<bool>(size,false));
    nQueen(board,size,0);
    return 0;
}
