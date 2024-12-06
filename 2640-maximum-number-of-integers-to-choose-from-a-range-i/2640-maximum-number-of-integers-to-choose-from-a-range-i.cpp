class Solution {
public:
    int maxCount(vector<int>& nums, int n, int maxSum) {
        unordered_set<int>setting;
        for(auto i: nums){
            setting.insert(i);
        }
        int sum = 0;
        int count = 0;
        for(int i=1; i<=n; i++){
            if(setting.find(i) == setting.end()){
                sum += i;
                if(sum <= maxSum) count++;
            }
        }
        return count;
    }
};