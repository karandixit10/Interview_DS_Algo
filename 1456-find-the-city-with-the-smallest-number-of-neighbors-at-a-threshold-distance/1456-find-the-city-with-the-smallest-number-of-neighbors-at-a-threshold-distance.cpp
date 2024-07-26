class Solution {
private:
    void dijkstra(int n, const vector<vector<pair<int, int>>>& adjacencyList, vector<int>& shortestPathDistances, int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        for(int i = 0; i < shortestPathDistances.size(); i++){
            shortestPathDistances[i] = INT_MAX;
        }
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& it: adjacencyList[node]){
                int adjNode = it.first;
                int dist = it.second;

                if (d + dist < shortestPathDistances[adjNode]) {
                    shortestPathDistances[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }

    }

    int getCityWithFewestReachable(int n,
                                   vector<vector<int>>& shortestPathMatrix,
                                   int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adjacencyList(n);
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;
        }

        for (auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adjacencyList[start].push_back({end, weight});
            adjacencyList[end].push_back({start, weight});
        }
        for (int i = 0; i < n; i++) {
            dijkstra(n, adjacencyList, shortestPathMatrix[i], i);
        }

        return getCityWithFewestReachable(n, shortestPathMatrix,
                                          distanceThreshold);
    }
};