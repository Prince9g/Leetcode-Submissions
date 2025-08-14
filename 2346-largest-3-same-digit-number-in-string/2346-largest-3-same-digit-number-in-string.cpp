class Solution {
public:
    bool check(string a){
        if(a[0] == a[1] && a[1] == a[2]) return true;
        return false;
    }
    string largestGoodInteger(string num) {
        int n = num.length();
        vector<string>nums;
        for(int i=0; i<n; i++){
            if(check(num.substr(i, 3))){
                nums.push_back(num.substr(i, 3));
            }
        }
        sort(nums.begin(), nums.end());
        if(nums.size() >= 1) return nums[nums.size()-1];
        return "";
    }
};