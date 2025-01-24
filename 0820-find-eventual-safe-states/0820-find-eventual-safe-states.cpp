class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVisited, vector<int>& safeNodes) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (int next : graph[node]) {
            if (!visited[next]) {
                if (!dfs(next, graph, visited, pathVisited, safeNodes)) {
                    return false;
                }
            }
            else if(pathVisited[next]){
                return false;
            }
        }
        safeNodes[node] = 1;
        pathVisited[node] = 0;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);
        vector<int> safeNodes(n, 0);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, graph, visited, pathVisited, safeNodes);
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safeNodes[i]) {
                result.push_back(i);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};