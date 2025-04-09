class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> seen;
        int operations = 0;
        while (nums.size() > 0) {
            bool allDistinct = true;
            seen.clear();
            for (int num : nums) {
                if (seen.count(num)) {
                    allDistinct = false;
                    break;
                }
                seen.insert(num);
            }
            if (allDistinct)
                break;
        int removeCount = min(3, (int)nums.size()); nums.erase(nums.begin(), nums.begin() + removeCount); operations++; } 
        return operations;
    }
    };