class Solution {
public:

    void solve(string s, unordered_set<string>&setting, vector<string>&ans, string helper, int index){
        int n = s.length();
        if(index >= n){
            if(helper.size() > n)
                ans.push_back(helper);
            return;
        }
        for(int i=index; i<n; i++){
            if(setting.find(s.substr(index,i-index+1)) != setting.end()){
                solve(s, setting, ans, helper+s.substr(index,i-index+1)+' ', i+1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>setting(wordDict.begin(), wordDict.end());
        vector<string>ans;
        string helper ="";
        solve(s, setting, ans, helper, 0);
        for(auto& a: ans){
            a.pop_back();
        }
        return ans;
    }
};