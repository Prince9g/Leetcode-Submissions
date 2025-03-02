class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mapping;
        for(auto i: nums1){
            mapping[i[0]] = i[1];
        }
        // int n = nums2.size();
        vector<vector<int>>ans;
        for(auto i: nums2){
            if(mapping.find(i[0]) != mapping.end()){
                int prev = mapping[i[0]];
                mapping[i[0]] = i[1] + prev;
            }else
                mapping[i[0]] = i[1];
        }
        for(auto mp: mapping){
            ans.push_back({mp.first, mp.second});
        }
        return ans;
    }
};