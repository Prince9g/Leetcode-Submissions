class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int number = original;
        for(int i=0; i<n; i++){
            if(nums[i] == number){
                number = nums[i]*2;
            }
        }
        return number;
    }
};