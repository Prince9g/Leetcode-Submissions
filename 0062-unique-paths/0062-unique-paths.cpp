class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D dp array initialized to 0
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the first row and the first column
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;  // Only one way to reach cells in the first column (down)
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;  // Only one way to reach cells in the first row (right)
    }

    // Fill the dp array using the relation dp[i][j] = dp[i-1][j] + dp[i][j-1]
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    // The value at the bottom-right corner is the number of unique paths
    return dp[m-1][n-1];
    }
};