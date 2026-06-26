class Solution {
public:
    long long dfs(int node, vector<vector<int>>& adj, vector<int>& baseTime) {
     
        if (adj[node].empty()) {
            return baseTime[node];
        }

        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;

        for (int child : adj[node]) {
            long long childFinish = dfs(child, adj, baseTime);

            earliest = min(earliest, childFinish);
            latest = max(latest, childFinish);
        }

        long long ownDuration = (latest - earliest) + baseTime[node];

        return latest + ownDuration;
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        return dfs(0, adj, baseTime);
    }
};