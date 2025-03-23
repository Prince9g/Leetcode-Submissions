class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto& i : roads) {
            adjList[i[0]].push_back({i[1], i[2]});
            adjList[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int mod = 1e9 + 7;

        while (!pq.empty()) {
            long long curDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& nbr : adjList[node]) {
                int nextNode = nbr.first;
                long long edgeWeight = nbr.second;

                if (curDist + edgeWeight < dist[nextNode]) {
                    dist[nextNode] = curDist + edgeWeight;
                    pq.push({dist[nextNode], nextNode});
                    ways[nextNode] = ways[node];  // New shortest path found
                } else if (curDist + edgeWeight == dist[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % mod;  // Additional shortest path found
                }
            }
        }

        return ways[n - 1];  // Number of ways to reach the destination node
    }
};
