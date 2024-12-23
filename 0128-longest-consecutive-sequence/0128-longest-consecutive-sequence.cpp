class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>temp;
        for(auto i: nums){
            temp.insert(i);
        }
        int longestCount = 0;
        vector<int>setting;
        int count = 1;
        setting.push_back(*temp.begin());
        for(auto i: temp){
            if(setting.back() + 1 == i) {
                count++;
                setting.push_back(i);
            }else{
                count = 1;
                setting.clear();
                setting.push_back(i);
            }
            if(count > longestCount) longestCount = count;
        }
        return longestCount;
    }
};