class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    // Base case: when we reach the bottom-right cell
    if (row == rows - 1 && col == cols - 1) {
        return grid[row][col];
    }

    // If this cell's result is already computed, return it
    if (dp[row][col] != -1) {
        return dp[row][col];
    }

    int right = INT_MAX, down = INT_MAX;

    // Try to move to the right cell if it's within bounds
    if (col + 1 < cols) {
        right = solve(grid, dp, row, col + 1);
    }

    // Try to move to the cell below if it's within bounds
    if (row + 1 < rows) {
        down = solve(grid, dp, row + 1, col);
    }

    // The minimum path sum from the current cell will be its value plus
    // the minimum of the right and down path sums
    dp[row][col] = grid[row][col] + min(right, down);

    return dp[row][col];
}

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1));  // Initialize dp table with -1 (uncomputed)

    return solve(grid, dp, 0, 0);  // Start from the top-left corner
}

};