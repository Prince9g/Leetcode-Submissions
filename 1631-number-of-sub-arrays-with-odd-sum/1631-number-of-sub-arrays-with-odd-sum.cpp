class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1; // evenCount = 1 for empty prefix sum
        int sum = 0, ans = 0;
        
        for (int num : arr) { // Go through each element
            sum += num; // Update prefix sum
            
            if (sum % 2 == 0) { 
                ans = (ans + oddCount) % MOD; // Odd subarrays end at this index
                evenCount++; // More even prefix sums
            } else { 
                ans = (ans + evenCount) % MOD; // Even subarrays end at this index
                oddCount++; // More odd prefix sums
            }
        }
        
        return ans;
    }
};
