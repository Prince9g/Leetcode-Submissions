class Solution {
public:
    int solveUsingRec(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1 && j == n-1){
            // sum++;
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //marking that we visited that
        grid[i][j] = -1;
        int ans = 0;
        //moving down
        if(i+1 < m && grid[i+1][j] == 0){
            ans += solveUsingRec(grid, i+1, j,dp);
        }
        //moving right
        if(j+1 < n && grid[i][j+1] == 0){
           ans += solveUsingRec(grid, i, j+1,dp);
        }
        grid[i][j] = 0;
        dp[i][j] = ans;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
        int ans = 0;
        if(grid[0][0] != 1)
            ans = solveUsingRec(grid, 0, 0, dp);
        return ans;
    }
};