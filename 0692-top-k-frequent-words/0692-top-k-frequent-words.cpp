class Solution {
public:
    typedef pair<string, int> P;
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        
        auto lambda = [](P& a, P& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };

        priority_queue<P, vector<P>, decltype(lambda)> pq(lambda);

        for(string &word : words) {
            mp[word]++;
        }
        
        for(auto &it : mp) {
            pq.push({it.first, it.second});
            
            if(pq.size() > k)
                pq.pop();
        }

        int i = k-1;
        vector<string> result(k);
        while(!pq.empty()) {
            result[i] = pq.top().first;
            pq.pop();
            i--;
        }
        
        return result;
    }
};