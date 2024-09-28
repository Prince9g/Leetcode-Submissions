#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cost(n, vector<int>(m, -1));
        queue<pair<int, int>> ZERO, ONE;
        
        auto push = [&](int y, int x, int c) {
            if (cost[y][x] < c) {
                if (grid[y][x]) ONE.push({y, x});
                else ZERO.push({y, x});
                cost[y][x] = c;
            }
        };
        
        push(0, 0, health - grid[0][0]);
        
        int dy[4] = {-1, 0, 1, 0};
        int dx[4] = {0, 1, 0, -1};
        
        while (!ZERO.empty() || !ONE.empty()) {
            while (!ZERO.empty()) {
                auto [y, x] = ZERO.front(); ZERO.pop();
                for (int i = 0; i < 4; ++i) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                        push(ny, nx, cost[y][x] - grid[ny][nx]);
                    }
                }
            }
            while (!ONE.empty() && ZERO.empty()) {
                auto [y, x] = ONE.front(); ONE.pop();
                for (int i = 0; i < 4; ++i) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                        push(ny, nx, cost[y][x] - grid[ny][nx]);
                    }
                }
            }
        }
        
        return cost[n - 1][m - 1] > 0;
    }
};