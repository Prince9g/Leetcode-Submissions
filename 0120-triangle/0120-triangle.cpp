class Solution {
public:
    int solveUsingRec(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        if(i < 0 || j < 0 || i >= m || j>= grid[i].size()) return 0;
        if(i == m-1) return grid[i][j];
        int isum = solveUsingRec(grid, i+1, j);
        int iplusSum  = solveUsingRec(grid, i+1, j+1);
        return grid[i][j] + min(isum, iplusSum);
    }
    int solveUsingMem(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&dp){
        int m = grid.size();
        if(i < 0 || j < 0 || i >= m || j>= grid[i].size()) return 0;
        if(i == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int isum = solveUsingMem(grid, i+1, j, dp);
        int iplusSum  = solveUsingMem(grid, i+1, j+1, dp);
        dp[i][j] = grid[i][j] + min(isum, iplusSum);
        return dp[i][j];
    }
    int solveUsingTabulation(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[m-1].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int i=m-1; i>=0; i--){
            for(int j=grid[i].size()-1; j>=0; j--){
                if(i == m-1) dp[i][j] = grid[i][j];
                else{
                    int isum = dp[i+1][j];
                    int iplusSum  = dp[i+1][j+1];
                    dp[i][j] = grid[i][j] + min(isum, iplusSum);
                }
            }
        }
        return dp[0][0];
    }
    int solveUsingTabulationSO(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[m-1].size();
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);
        for(int i=m-1; i>=0; i--){
            for(int j=grid[i].size()-1; j>=0; j--){
                if(i == m-1) curr[j] = grid[i][j];
                else{
                    int isum = next[j];
                    int iplusSum  = next[j+1];
                    curr[j] = grid[i][j] + min(isum, iplusSum);
                }
            }
            //baar baar shift krna mt bhole bhaiyaa
            next = curr;
        }
        return curr[0];
    }
    int minimumTotal(vector<vector<int>>& grid) {
        // int m = grid.size();
        // int n = grid[m-1].size();
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        return solveUsingTabulationSO(grid);
    }
};