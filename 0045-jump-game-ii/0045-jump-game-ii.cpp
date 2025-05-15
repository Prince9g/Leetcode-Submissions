class Solution {
public:
    int solveUsingRec(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size() - 1) return 0; // Reached or surpassed the last index
        if (dp[i] != -1) return dp[i];     // Return cached result

        int mini = nums.size();
        for (int j = 1; j <= nums[i]; j++) { // Explore all possible jumps
            mini = min(mini, 1 + solveUsingRec(nums, i + j, dp));
        }

        return dp[i] = mini; // Cache and return the result
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1); // Initialize memoization table
        return solveUsingRec(nums, 0, dp);
    }
};