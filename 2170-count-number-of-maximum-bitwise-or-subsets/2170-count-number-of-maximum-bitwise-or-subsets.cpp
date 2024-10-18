class Solution {
public:
    void solve(vector<int>& nums, int currOr, int index, int &maxOr, int &count) {
        // Base case: when index goes out of bounds
        if (index == nums.size()) {
            if (currOr > maxOr) {
                maxOr = currOr;  // Update the maximum OR value
                count = 1;  // Reset count if new max OR is found
            } else if (currOr == maxOr) {
                count++;  // Increment count for current maximum OR
            }
            return;
        }

        // Include the current element (OR operation with nums[index])
        solve(nums, currOr | nums[index], index + 1, maxOr, count);

        // Exclude the current element (no OR operation)
        solve(nums, currOr, index + 1, maxOr, count);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        int count = 0;
        solve(nums, 0, 0, maxOr, count);
        return count;
    }
};
