class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    // Step 1: Sort the array
    sort(nums.begin(), nums.end());

    // Step 2: Traverse the array
    for(int i = 0; i < nums.size(); i++) {
        // Skip duplicate values for the first element
        if(i > 0 && nums[i] == nums[i-1]) continue;

        // Two pointers approach
        int left = i + 1;
        int right = nums.size() - 1;

        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicate values for the second element
                while(left < right && nums[left] == nums[left + 1]) left++;
                // Skip duplicate values for the third element
                while(left < right && nums[right] == nums[right - 1]) right--;

                // Move the pointers
                left++;
                right--;
            }
            else if(sum < 0) {
                // Move the left pointer to the right to increase the sum
                left++;
            }
            else {
                // Move the right pointer to the left to decrease the sum
                right--;
            }
        }
    }
    
    return ans;
}

};