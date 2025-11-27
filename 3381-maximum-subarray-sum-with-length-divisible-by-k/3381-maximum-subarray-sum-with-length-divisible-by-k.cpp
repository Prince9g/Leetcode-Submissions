class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        long long maxSum = LLONG_MIN;
        
        // Partition by modulo k
        for(int r=0; r<k; r++){
            long long minPrefix = LLONG_MAX;
            for(int i=r; i<=n; i+=k){
                if(minPrefix != LLONG_MAX){
                    maxSum = max(maxSum, prefix[i] - minPrefix);
                }
                minPrefix = min(minPrefix, prefix[i]);
            }
        }
        
        return maxSum;
    }
};
