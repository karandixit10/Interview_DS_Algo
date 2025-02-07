class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result;
        unordered_map<int, int> ballColors;
        unordered_map<int, int> colorCount;
        unordered_set<int> distinctColors;
        for (const auto& query : queries) {
            int ball = query[0];
            int newColor = query[1];
            if (ballColors.find(ball) != ballColors.end()) {
                int oldColor = ballColors[ball];
                //old Color remove kro
                colorCount[oldColor]--;

                if (colorCount[oldColor] == 0) {
                    colorCount.erase(oldColor);
                    distinctColors.erase(oldColor);
                }
            }

            ballColors[ball] = newColor;
            colorCount[newColor]++; // Increase count of the new color
            distinctColors.insert(newColor);
            result.push_back(distinctColors.size());
        }
        return result;
    }
};