class Solution {
public:
    bool check(vector<string>&words, int prev, int curr){
        int skip=false;
        string a = words[prev];
        string b = words[curr];
        int i=0,j=0,m=a.length(),n=b.length();
        // if(m==n) return false;
        if(abs(m-n) != 1) return false;
        while(i < m && j < n){
            if(a[i] == b[j]){
                i++;
            }else{
                if(skip) return false;
                else skip = true;
            }
            j++;
        }
        return true;
    }
    vector<vector<int>>dp;
    int f(vector<string>&words, int prev, int curr){
        int n = words.size();
        if(curr >= n) return 0;
        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];
        int inc = 0, exc = 0;
        if(prev == -1 || check(words, prev, curr)){
            inc = 1 + f(words, curr, curr + 1);
        }
        exc = f(words, prev, curr+1);
        return dp[prev+1][curr] = max(inc, exc);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string a, string b){
            return a.length() < b.length();
        });
        dp.resize(words.size()+2, vector<int>(words.size()+2, -1));
        return f(words, -1, 0);
    }
};