class Solution {
private:
    int rows;
    int cols;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isSubIsland(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited) {
        int isSub = true;
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        while (!q.empty()) {
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();
            if (grid1[currX][currY] != 1) {
                isSub = false;
            }
            for(auto &dir : directions){
                int nextX = currX + dir[0];
                int nextY = currY + dir[1];
                if(nextX >= 0 && nextY >= 0 && nextX < rows && nextY < cols && !visited[nextX][nextY] && grid2[nextX][nextY] == 1){
                    q.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                }
            }
        }
        return isSub;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        rows = grid2.size();
        cols = grid2[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int res = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid2[i][j] == 1 && isSubIsland(i, j, grid1, grid2, visited)) {
                    res++;
                }
            }
        }
        return res;
    }
};