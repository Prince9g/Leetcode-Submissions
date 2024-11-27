class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
    vector<vector<int>> adj(n);
    // Initialize the initial roads from i to i + 1
    for (int i = 0; i < n - 1; ++i) {
        adj[i].push_back(i + 1);
    }
    
    // Function to find the shortest path from 0 to n-1 using BFS
    auto bfs = [&]() -> int {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[n - 1];
    };
    
    for (const auto& query : queries) {
        int u = query[0];
        int v = query[1];
        adj[u].push_back(v);
        answer.push_back(bfs());
    }
    
    return answer;
    }
};