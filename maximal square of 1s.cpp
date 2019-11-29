int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if(m==0)
        return 0;
    int n = matrix[0].size();
    if(n==0)
        return 0;
    int result=0;

    //two loops for top left corner
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]=='1')
            {
                int size;
                size = min(m-i,n-j);

                //loop for all sizes of squares starting from that top left corner
                for(int s=1;s<=size;s++)
                {
                    int xlim=i+s;
                    int ylim=j+s;
                    bool maxsquare = true;

                    //loop for all elements of the square
                    for(int k=i;k<xlim;k++)
                    {
                        for(int l=j;l<ylim;l++)
                        {
                            if(matrix[k][l]!='1')
                            {
                                maxsquare=false;
                                break;
                            }
                        }
                        if(!maxsquare)
                        break;
                    }
                    if(maxsquare)
                        result=max(result,s);
                }
            }
        }
    }
    return result*result;
}
