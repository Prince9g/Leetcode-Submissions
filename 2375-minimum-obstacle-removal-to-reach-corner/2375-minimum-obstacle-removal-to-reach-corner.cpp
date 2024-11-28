class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); // Distance (minimum obstacles)
        dist[0][0] = 0;

        // Min-heap: {obstacles_removed, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0}); // Start from (0, 0) with 0 obstacles removed

        // Direction vectors: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            auto [obstacles, i, j] = pq.top();
            pq.pop();

            // If we reach the bottom-right corner
            if (i == m - 1 && j == n - 1) {
                return obstacles;
            }

            // Explore neighbors
            for (auto [dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;

                // Check bounds
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int new_obstacles = obstacles + grid[x][y];

                    // Update distance if a better path is found
                    if (new_obstacles < dist[x][y]) {
                        dist[x][y] = new_obstacles;
                        pq.push({new_obstacles, x, y});
                    }
                }
            }
        }

        return -1; // Unreachable (shouldn't happen in a valid grid)
    }
};
