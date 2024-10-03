class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
    long long sumOverall = 0;
    for (auto i : nums) {
        sumOverall += i;
    }

    long long remove = sumOverall % p;
    if (remove == 0) {
        return 0; // Already divisible by p, no need to remove any subarray
    }

    unordered_map<int, int> prefixMap; // Tracks prefix sum mod p
    prefixMap[0] = -1; // To handle subarrays starting from index 0
    long long prefixSum = 0;
    int mini = nums.size(); // Initialize with the maximum possible size

    for (int i = 0; i < nums.size(); i++) {
        prefixSum = (prefixSum + nums[i]) % p;

        // Calculate the target remainder we need
        long long target = (prefixSum - remove + p) % p;

        // If we've seen this remainder before, we found a valid subarray
        if (prefixMap.find(target) != prefixMap.end()) {
            mini = min(mini, i - prefixMap[target]);
        }

        // Store the current prefix mod p with its index
        prefixMap[prefixSum] = i;
    }

    // If mini is still the size of the array, we didn't find any valid subarray
    return mini == nums.size() ? -1 : mini;
}

};