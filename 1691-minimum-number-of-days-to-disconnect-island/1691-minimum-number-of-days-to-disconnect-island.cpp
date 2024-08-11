class Solution {
private:
    const vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int countIslands(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islandCount = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!visited[row][col] && grid[row][col] == 1) {
                    dfs(grid, row, col, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
    void dfs(vector<vector<int>>& grid, int row, int col,
             vector<vector<bool>>& visited) {
        visited[row][col] = true;
        for (const auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 &&
                newCol < grid[0].size() && !visited[newRow][newCol] &&
                grid[newRow][newCol] == 1) {
                dfs(grid, newRow, newCol, visited);
            }
        }
    }

public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int oldCount = countIslands(grid);
        // Already disconnected or no land
        if (oldCount != 1) {
            return 0;
        }

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) // water
                    continue;
                
                grid[row][col] = 0;
                int newCount = countIslands(grid);
                if (newCount != 1)
                    return 1;

                grid[row][col] = 1;
            }
        }
        return 2;
    }
};