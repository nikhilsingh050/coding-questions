bool SolveSudoku(int grid[N][N])
{
    int row, col;

    // find unassigned cell(row,col value)
    // if not found -> sudoku is solved
    if (!FindUnassignedLocation(grid, row, col)) //call by reference
        return true;

    //possible values 1to 9
    for (int num = 1; num <= 9; num++)
    {
        // if move is safe considering row,column and sub-grid
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (SolveSudoku(grid))
                return true;

            // failure, unmark & try next value
            grid[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
}




///////////////////////////////////////////////////////////////////////////

//check if there is unassigned cell -> update row and col
bool FindUnassignedLocation(int grid[N][N],
                            int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}


bool isSafe(int grid[N][N], int row,
                   int col, int num)
{
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 ,
                      col - col % 3, num) &&
            grid[row][col] == UNASSIGNED;
}


bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}


bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}


bool UsedInBox(int grid[N][N], int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] == num)
                return true;
    return false;
}
