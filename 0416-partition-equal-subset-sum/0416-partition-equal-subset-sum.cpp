class Solution {
public:
    int tSum;
    bool solve(vector<int>&nums, int sum, int index, vector<vector<int>>&dp){
        if(index >= nums.size()) return false;
        if(sum == tSum) return true;
        if(sum > tSum) return false;
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        int include = solve(nums, sum+nums[index], index+1, dp);
        int exclude = solve(nums, sum, index+1, dp);
        dp[index][sum] = (include || exclude);
        return dp[index][sum];
    }
    bool solveUsingTabulation(vector<int>&nums){
        int m = nums.size();
        vector<vector<bool>>dp(m+1, vector<bool>(tSum+1,false));
        for(int i=0; i<=m;i++){
            dp[i][0] = true;
        }
        for(int index=m-1; index>=0; index--){
            for(int sum=0; sum<=tSum; sum++){
                bool include = (sum >= nums[index]) ? dp[index + 1][sum - nums[index]] : false;
                bool exclude = dp[index + 1][sum];
                dp[index][sum] = include || exclude;
            }
        }
        return dp[0][tSum];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;
        int tSum = totalSum / 2;

        vector<bool> dp(tSum + 1, false);
        dp[0] = true;  // A sum of 0 is always achievable

        for (int num : nums) {
            for (int j = tSum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];  // Include or exclude current number
            }
        }
        return dp[tSum];
    }
};