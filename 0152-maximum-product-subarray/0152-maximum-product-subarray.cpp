class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(suffix==0) suffix = 1;
            if(prefix == 0) prefix = 1;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            maxi  = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};