class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int s=0,e=0;
        int n = nums.size();
        long long sum = 0;
        while(e < n){
            if(nums[e] == 0){
                sum += (e-s+1);
                e++;
            }
            else{
                e++;
                s = e;
            }
        }
        return sum;
    }
};