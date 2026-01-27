class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int cP = 0;
        vector<int>temp;
        for(auto i: nums){
            if(i >= 0) temp.push_back(i);
        }
        cP = temp.size();
        if(temp.size() != 0){
            k = k%cP;
            reverse(temp.begin(), temp.begin()+k);
            reverse(temp.begin()+k, temp.end());
            reverse(temp.begin(), temp.end());
        }
        int p = 0;
        // for(auto i: temp) cout << i << " ";
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=0 && p < temp.size()){
                nums[i] = temp[p];
                p++;
            }
        }
        return nums;
    }
};