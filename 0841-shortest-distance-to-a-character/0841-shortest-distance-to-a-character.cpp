class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>mapping;
        vector<int>ans;
        int n = s.length();
        for(int i=0; i<s.length(); i++){
            if(s[i] == c){
                mapping.push_back(i);
            }
        }
        for(int i=0; i<n; i++){
            int mini = INT_MAX;
            for(int j=0; j<mapping.size(); j++){
                mini = min(abs(i-mapping[j]), mini);
            }
            ans.push_back(mini);
        }
        return ans;
    }
};