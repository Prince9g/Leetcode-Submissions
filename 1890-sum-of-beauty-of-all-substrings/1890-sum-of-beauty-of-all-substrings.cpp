class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int c = 0;
        for(int i=0; i<n; i++){
            string temp = "";
            unordered_map<char,int>mp;
            for(int j=i; j<n; j++){
                temp += s[j];
                mp[s[j]]++;
                if(mp.size()>1){
                    int mini = 501,maxi=-1;
                    for(auto i: mp){
                        maxi = max(maxi, i.second);
                        mini = min(mini, i.second);
                    }
                    c+= (maxi-mini);
                }
            }
        }
        return c;
    }
};