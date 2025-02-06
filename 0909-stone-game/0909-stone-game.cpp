class Solution {
public:
    int lvl = -1;
    int solve(vector<int>&piles, int s, int e){
        if(s == e) return piles[s];
        if(s > e) return 0;
        int alice = 0,bob=0;
        lvl++;
        if(lvl % 2 == 0){
            int option1 = piles[s] + solve(piles,s+1, e);
            int option2 = piles[e] + solve(piles, s, e-1);
            alice = max(option1, option2);
        }else{
            int option1 = piles[s] + solve(piles,s+1, e);
            int option2 = piles[e] + solve(piles, s, e-1);
            bob = max(option1, option2);
        }
        // cout << bob << endl;
        return alice > bob ? 1:0;
    }
    int solveUsingMem(vector<int>&piles, int s, int e, vector<vector<int>>&dp){
        if(s == e) return piles[s];
        if(s > e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        int alice = 0,bob=0;
        lvl++;
        if(lvl % 2 == 0){
            int option1 = piles[s] + solveUsingMem(piles,s+1, e, dp);
            int option2 = piles[e] + solveUsingMem(piles, s, e-1, dp);
            alice = max(option1, option2);
        }else{
            int option1 = piles[s] + solveUsingMem(piles,s+1, e, dp);
            int option2 = piles[e] + solveUsingMem(piles, s, e-1, dp);
            bob = max(option1, option2);
        }
        // cout << bob << endl;
        dp[s][e] = alice > bob ? 1:0;
        return dp[s][e];
    }
    int solveUsingTabulation(vector<int>&piles){
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int s=0; s<n; s++){
            for(int e=0; e<n; e++){
                if(s == e) dp[s][e] = piles[s];
            }
        }
        for(int s=n-1; s>=0; s--){
            for(int e=s+1; e<n; e++){
                int lvl = (e - s + 1);
                int alice = 0,bob=0;
                if(lvl % 2 == 0){
                    int option1 = piles[s] + (s + 1 <= e ? dp[s + 1][e] : 0);
                    int option2 = piles[e] + (s <= e - 1 ? dp[s][e - 1] : 0);
                    alice = max(option1, option2);
                }else{
                    int option1 = piles[s] + (s + 1 <= e ? dp[s + 1][e] : 0);
                    int option2 = piles[e] + (s <= e - 1 ? dp[s][e - 1] : 0);
                    bob = max(option1, option2);
                }
                dp[s][e] = alice > bob ? 1:0;
            }
        }
        return dp[0][n-1];
    }

    int solveUsingTabulationSO(vector<int>&piles){
        int n = piles.size();
        vector<int>curr(n, 0);
        vector<int>next(n, 0);
        next[n-1] = piles[n-1];
        curr[n-2] = piles[n-2];
        for(int s=n-1; s>=0; s--){
            for(int e=s+1; e<n; e++){
                int lvl = (e - s + 1);
                int alice = 0,bob=0;
                if(lvl % 2 == 0){
                    int option1 = piles[s] + (s + 1 <= e ? next[e] : 0);
                    int option2 = piles[e] + (s <= e - 1 ? curr[e - 1] : 0);
                    alice = max(option1, option2);
                }else{
                    int option1 = piles[s] + (s + 1 <= e ? next[e] : 0);
                    int option2 = piles[e] + (s <= e - 1 ? curr[e - 1] : 0);
                    bob = max(option1, option2);
                }
                curr[e] = alice > bob ? 1:0;
            }
            next = curr;
        }
        return curr[n-1];
    }
    bool stoneGame(vector<int>& piles) {
        // // int n = piles.size();
        // // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // // int s=0,e=piles.size()-1;
        // int ans = solveUsingTabulationSO(piles);
        // return ans == 1 ? true: false;
        return true;
    }
};