class Solution {
public:
    void solve(vector<int>& nums, int target, int &sum, int index, int helper){
        if(index == nums.size()){
            if(target == helper){
                sum++;
            }
            return;
        }
        solve(nums, target, sum, index+1, helper+nums[index]);
        solve(nums,target,sum, index+1, helper-nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        solve(nums, target, sum, 0, 0);
        return sum;
    }
};