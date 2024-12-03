class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int j=0;
        for(int i=0; i<s.length(); i++){
            if(i < s.length() && j < spaces.size() && i == spaces[j]){
                ans.push_back(' ');
                j++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};