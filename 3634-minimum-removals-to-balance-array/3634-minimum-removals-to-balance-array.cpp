class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mini = INT_MAX;
        vector<long long>mul;
        for(auto i: nums){
            mul.push_back(1LL*i*k);
        }
        for(int i=n-1; i>=0; i--){
            int lb = lower_bound(mul.begin(), mul.end(), nums[i]) - mul.begin();
            // if(lb - 1 >= 0 && l)
            mini = min(mini, n-i-1 + lb);
        }
        return mini;
    }
};