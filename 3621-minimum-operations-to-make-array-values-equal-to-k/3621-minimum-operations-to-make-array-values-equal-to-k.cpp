class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for(int i=n-2; i>=0; i--){
            if(nums[i] != nums[i+1]){
                count++;
            }
        }
        if(nums[0] < k) return -1;
        if(nums[0] != k) return count+1;
        return count;
    }
};