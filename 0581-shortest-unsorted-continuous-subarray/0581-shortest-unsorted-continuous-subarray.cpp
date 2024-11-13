class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int s = -1, e = -1;

        // Step 1: Identify initial boundaries of the unsorted subarray
        for(int i = 1; i < n; ++i) {
            if(nums[i] < nums[i - 1]) {
                s = i - 1;
                break;
            }
        }
        if(s == -1) return 0; // Array is already sorted

        for(int i = n - 2; i >= 0; --i) {
            if(nums[i] > nums[i + 1]) {
                e = i + 1;
                break;
            }
        }

        // Step 2: Find min and max in the subarray nums[s..e]
        int subarray_min = *min_element(nums.begin() + s, nums.begin() + e + 1);
        int subarray_max = *max_element(nums.begin() + s, nums.begin() + e + 1);

        // Step 3: Expand `s` and `e` to include any numbers out of order
        while(s > 0 && nums[s - 1] > subarray_min) --s;
        while(e < n - 1 && nums[e + 1] < subarray_max) ++e;

        return e - s + 1;
    }
};
