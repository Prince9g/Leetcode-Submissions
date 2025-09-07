class Solution {
public:
    int minOperations(vector<int>& nums) {
        for(auto i: nums){
            if(i != nums[0]) return 1;
        }
        return 0;
    }
};