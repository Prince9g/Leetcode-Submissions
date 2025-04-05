class Solution {
public:
    int solveUsingRec(vector<int>&nums, int prev, int curr){
        if(curr >= nums.size()) return 0;
        int ans = 0,include=0,exclude=0;
        if(prev == -1 || nums[prev] < nums[curr]){
            include = 1 + solveUsingRec(nums, curr, curr+1);
        }
        exclude = 0 + solveUsingRec(nums, prev, curr+1);
        ans = max(include,exclude);
        return ans;
    }
    int solveUsingMem(vector<int>&nums, int prev, int curr, vector<vector<int>>&dp){
        if(curr >= nums.size()) return 0;
        if(dp[prev+1][curr] != -1){
            return dp[prev+1][curr];
        }
        int include=0,exclude=0;
        if(prev == -1 || nums[prev] < nums[curr]){
            include = 1 + solveUsingMem(nums, curr, curr+1, dp);
        }
        exclude = 0 + solveUsingMem(nums, prev, curr+1, dp);
        dp[prev+1][curr] = max(include,exclude);
        return dp[prev+1][curr];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solveUsingMem(nums, -1, 0,dp);
    }
};