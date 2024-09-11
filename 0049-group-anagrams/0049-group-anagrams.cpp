class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>umap;
        
        //Create unordered map
        for(auto x: strs){
            string temp = x;
            sort(x.begin(), x.end());
            umap[x].push_back(temp);
        }
      
        //push the keys from umap to ans
        for(auto x : umap){
            ans.push_back(x.second);
        }
        return ans;
    }
};