class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        long rows=0;
        long cols=0;
        for(int i = 0 ; i < row; i++){
            for(int j = 0; j < col/2; j++){
                if(grid[i][j] != grid[i][col-j-1]){
                    rows++;
                }
            }
        }
        for(int i = 0 ; i < col; i++){
            for(int j = 0; j < row/2; j++){
                if(grid[j][i] != grid[row-j-1][i]){
                    cols++;
                }
            }
        }
        return min(rows,cols);
    }
};