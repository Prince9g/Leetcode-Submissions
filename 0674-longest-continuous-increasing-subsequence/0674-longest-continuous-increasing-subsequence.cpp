class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxCount = 1;
        int n = nums.size();
        int count = 1;
        for(int i=0; i<n; i++){
            if(i+1 < n && nums[i] < nums[i+1]){
                count++;
            }
            else{
                count = 1;
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};