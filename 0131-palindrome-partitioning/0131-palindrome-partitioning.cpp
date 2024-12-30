class Solution {
public:
    bool checkPalindrome(string s, int i, int e){
        while(i <= e){
            if(s[i] != s[e]){
                return false;
            }
            i++;e--;
        }
        return true;
    }
    void solve(string s, int index, vector<vector<string>>&ans, vector<string>helper){
        if(index >= s.length()){
            ans.push_back(helper);
            return;
        }

        for(int i=index; i<s.length(); i++){
            if(checkPalindrome(s, index, i)){
                helper.push_back(s.substr(index, i-index+1));
                solve(s, i+1, ans, helper);
                helper.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>helper;
        solve(s, 0, ans, helper);
        return ans;
    }
};