class Solution {
public:
    const int MOD = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> suffixFreq, prefixFreq;
        int n = nums.size();

        // Initialize suffix frequencies
        for (int i = 0; i < n; i++) {
            suffixFreq[nums[i]]++;
        }

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            suffixFreq[nums[j]]--;  // We are at j, so remove from suffix

            int val = nums[j] * 2;
            long long left = prefixFreq[val];
            long long right = suffixFreq[val];

            ans = (ans + (left * right) % MOD) % MOD;

            prefixFreq[nums[j]]++;  // Add current number to prefix
        }

        return (int)ans;
    }
};
