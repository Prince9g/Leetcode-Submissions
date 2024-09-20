class Solution {
public:
    int thirdMax(vector<int>& nums) {
    // Sort the array in descending order
    sort(nums.begin(), nums.end(), greater<int>());
    
    // Remove duplicates by using unique
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    // If there are less than 3 distinct numbers, return the largest
    if (nums.size() < 3) {
        return nums[0]; // Maximum number
    } else {
        return nums[2]; // Third maximum number
    }
}
};