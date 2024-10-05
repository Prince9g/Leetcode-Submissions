class Solution {
public:
    // using dfs traversal
    bool helper(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    // Check if out of bounds or already visited or water ('0')
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == '0') {
        return false;
    }

    // Mark the current cell as visited
    visited[i][j] = true;

    // Recursively visit all adjacent cells (4 directions)
    helper(grid, visited, i + 1, j); // Down
    helper(grid, visited, i - 1, j); // Up
    helper(grid, visited, i, j + 1); // Right
    helper(grid, visited, i, j - 1); // Left

    return true;
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // If the current cell is land ('1') and not visited, it's a new island
            if (!visited[i][j] && grid[i][j] == '1') {
                if (helper(grid, visited, i, j)) {
                    count++;
                }
            }
        }
    }

    return count;
}

};