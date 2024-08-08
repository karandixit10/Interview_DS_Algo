class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<vector<int>> directions{{0, 1}, // East
                                {1, 0}, //South
                                {0 , -1}, //West
                                {-1, 0}}; // North
        
        int step = 0;
        int dir  = 0;
        result.push_back({rStart, cStart});
        while(result.size() < rows * cols) {
            if(dir == 0 || dir == 2) step++;

            for(int i = 0; i < step; i++){
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    result.push_back({rStart, cStart});
                }
            }

            dir = (dir + 1) % 4;
        }

        return result;
        

    }
};