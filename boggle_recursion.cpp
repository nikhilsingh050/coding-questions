//Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character.
//Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any
//of 8 adjacent characters, but a word should not have multiple instances of same cell.

#include<bits/stdc++.h>
using namespace std;

int m,n;

//row and col for 8 possible moves
//{L,R,U,D,UL,UR,DR,DL}
int rowMoves[]={0,0,-1,1,-1,-1,1,1};
int colMoves[]={-1,1,0,0,-1,1,1,-1};


//find given word in dictionary
bool inDictionary(vector<string> dictionary,string word)
{
    for(int i=0;i<dictionary.size();i++)
    {
        if(dictionary[i]==word)
            return true;
    }
    return false;
}

//check if given move is possible
bool isValidMove(int row,int col,vector<vector<bool>> visited)
{
    if(row >=0 && row<m && col>=0 && col<n && !visited[row][col])
        return true;
    else
        return false;
}

//backtracking through all possible combination of words AND print if a word is present in dictionary
void printWords(vector<vector<char>> boggle,vector<string> dictionary,vector<vector<bool>> visited,int row, int col,string word)
{
    if(inDictionary(dictionary,word))
        cout<<word<<endl;

    if(word.length()==9)
        return;

    //calls for all possible 8 moves
    for(int i=0;i<8;i++)
    {
        int newRow = row + rowMoves[i];
        int newCol = col + colMoves[i];

        if(isValidMove(newRow,newCol,visited))
        {
            visited[newRow][newCol] = true;
            printWords(boggle,dictionary,visited,newRow,newCol,word+boggle[newRow][newCol]);
            visited[newRow][newCol] = false;
        }
    }
}

//utility function for printWords
void findWords(vector<vector<char>> boggle, vector<string> dictionary)
{
    //initializing visited table with false.
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    string word="";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            visited[i][j]=true;
            printWords(boggle,dictionary,visited,i,j,word+boggle[i][j]);
            visited[i][j]=false;
        }
    }
}

int main()
{
    vector<vector<char>> boggle = { { 'N', 'H', 'S' },
                                    { 'I', 'I', 'K' },
                                    { 'L', 'E', 'T' } };
    m=n=3;

    vector<string> dictionary = {"NIKHIL", "LIKE", "NIKE", "BALL"};

    cout << "Following words of dictionary are present: \n";
    findWords(boggle,dictionary);
    return 0;
}
