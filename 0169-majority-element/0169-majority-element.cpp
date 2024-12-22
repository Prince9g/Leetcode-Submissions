class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size()-1;
        return nums[(s+e)/2];
    }
};