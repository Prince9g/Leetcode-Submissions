class Solution {
public:
    bool isValid(string s){
        // int n = s.length();
        if(s.empty()) return false;
        for(auto i: s){
            if((i>='a' && i<='z') || (i>='A' && i<='Z') || (i>='0' && i<='9') || (i == '_')) continue;
            else return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>nums;
        for(int i=0; i<code.size(); i++){
            if(isValid(code[i]) && (businessLine[i] == "restaurant" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "electronics") && isActive[i]){
                //category, code
                nums.push_back({businessLine[i], code[i]});
            }
        }
        sort(nums.begin(), nums.end(), [&](pair<string,string>a, pair<string,string>b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        vector<string>ans;
        for(auto i: nums){
            ans.push_back(i.second);
        }
        return ans;
    }
};