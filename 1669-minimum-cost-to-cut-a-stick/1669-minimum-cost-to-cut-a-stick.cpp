class Solution {
public:
    int f(vector<int>&cuts, int s, int e, vector<vector<int>>&dp){
        if(s > e) return 0;
        int mini = INT_MAX;
        if(dp[s][e] != -1) return dp[s][e];
        for(int i=s; i<=e; i++){
            int cut = cuts[e+1] - cuts[s-1] + f(cuts, s, i-1, dp) + f(cuts, i+1, e, dp);
            mini = min(mini, cut);
        }
        return dp[s][e] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>>dp(c+2, vector<int>(c+2, -1));
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return f(cuts, 1, c, dp);
    }
};