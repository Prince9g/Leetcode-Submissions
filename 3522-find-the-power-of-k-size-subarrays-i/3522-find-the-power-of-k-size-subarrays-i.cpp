class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
    vector<int> result;

    for (int i = 0; i <= n - k; ++i) {
        bool isValid = true;
        int maxElement = nums[i];

        for (int j = i + 1; j < i + k; ++j) {
            if (nums[j] <= nums[j - 1] || nums[j] != nums[j - 1] + 1) {
                isValid = false;
                break;
            }
            maxElement = max(maxElement, nums[j]);
        }

        if (isValid) {
            result.push_back(maxElement);
        } else {
            result.push_back(-1);
        }
    }

    return result;
    }
};