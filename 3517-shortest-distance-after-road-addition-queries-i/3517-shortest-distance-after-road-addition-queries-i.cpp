class Solution {
private:
    int dijkastra(vector<vector<int>>& adj, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        pq.push({0,0});
        vector<int> dist(n, INT_MAX);
        while(!pq.empty()){
            int node = pq.top().first;
            int dis = pq.top().second;
            pq.pop();
            for(auto& it: adj[node]){
                if(dis + 1 < dist[it]){
                    dist[it] = dis + 1;
                    pq.push({it, dist[it]});
                }
            }
        }
        return dist[n-1];
    }

public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> answer(queries.size());
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        for (int i = 0; i < queries.size(); i++) {
            adj[queries[i][0]].push_back(queries[i][1]);
            answer[i] = dijkastra(adj, n);
        }
        return answer;
    }
};