class Solution {
public:
    int solveUsingRec(vector<int>& nums, int prev, int curr){
        if(curr >= nums.size()){
            return 0;
        }
        //processing using include and exclude pattern
        int include = 0,exclude=0;
        if(prev == -1 || nums[prev] < nums[curr]){
            include = 1 + solveUsingRec(nums, curr, curr+1);
        }
        exclude = 0 + solveUsingRec(nums, prev, curr+1);
        return max(include, exclude);
    }
    int solveUsingMem(vector<int>& nums, int prev, int curr, vector<vector<int>>&dp){
        if(curr >= nums.size()){
            return 0;
        }
        //processing using include and exclude pattern
        if(dp[prev+1][curr] != -1){
            return dp[prev+1][curr];
        }
        int include = 0,exclude=0;
        if(prev == -1 || nums[prev] < nums[curr]){
            include = 1 + solveUsingMem(nums, curr, curr+1,dp);
        }
        exclude = 0 + solveUsingMem(nums, prev, curr+1,dp);
        dp[prev+1][curr] = max(include, exclude);
        return dp[prev+1][curr];
    }
    int solveUsingTabulation(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        // for(int i=0; i<=n; i++){
        //     dp[n][i] = 0;
        // }
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                int include = 0,exclude=0;
                if(j == -1 || nums[i] > nums[j]){
                    include = 1 + dp[i+1][i+1];
                }
                exclude = 0 + dp[i+1][j+1];
                dp[i][j+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int solveUsingTabulationSO(vector<int>&nums){
        int n = nums.size();
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                int include = 0,exclude=0;
                if(j == -1 || nums[i] > nums[j]){
                    include = 1 + next[i+1];
                }
                exclude = 0 + next[j+1];
                curr[j+1] = max(include, exclude);
            }
            next = curr;
        }
        return curr[0];
    }
    int solveUsingBS(vector<int>&nums){
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size();i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                //there exists a just higher number from the nums array
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size()+2, vector<int>(nums.size()+1, -1));
        return solveUsingBS(nums);
    }
};