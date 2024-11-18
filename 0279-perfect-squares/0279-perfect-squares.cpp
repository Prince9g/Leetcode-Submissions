class Solution {
public:
    int solve(int n,  vector<int>&dp){
        if(n == 0) return 0;
        int recAns = n;
        if(dp[n] != -1){
            return dp[n];
        }
        for(int i=1; i*i <=n; i++){
            recAns = min(recAns, 1 + solve(n-i*i, dp));
        }
        return dp[n] = recAns;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n, dp);
    }
};