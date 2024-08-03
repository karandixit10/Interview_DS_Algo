class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }
        for (int &num : target) {
            if (mp.find(num) == mp.end())
                return false;
            mp[num]--;
            if (mp[num] == 0) {
                mp.erase(num);
            }
        }
        return mp.size() == 0;
    }
};