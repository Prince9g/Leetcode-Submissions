#include <set>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window; // Use long long to avoid overflow issues

        for (int i = 0; i < nums.size(); i++) {
            // Maintain a window of `indexDiff` elements
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }

            // Find the closest element in the current window that might satisfy the `valueDiff` condition
            auto pos = window.lower_bound((long long)nums[i] - valueDiff);

            // Check if the found element is within the required `valueDiff` distance
            if (pos != window.end() && abs(*pos - nums[i]) <= valueDiff) {
                return true;
            }

            // Insert the current element into the window
            window.insert(nums[i]);
        }

        return false;
    }
};
