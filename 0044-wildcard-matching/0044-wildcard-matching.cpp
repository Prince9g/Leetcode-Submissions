class Solution {
public:
    bool solveUsingRec(string &a, string &b, int i, int j){
        int m = a.length();
        int n = b.length();
        if(i == m && j == n) return true;
        if(i == m){
            bool flag = 1;
            for(int k=j; k<n; k++){
                if(b[k] != '*') flag = 0;
            }
            return flag;
        }
        // int option = false;
        if(a[i] == b[j] || b[j] == '?'){
            return solveUsingRec(a, b, i+1, j+1);
        }else if(b[j] == '*'){
            int option1 = solveUsingRec(a, b, i+1, j);
            int option2 = solveUsingRec(a,b, i+1, j+1);
            int option3 = solveUsingRec(a, b, i, j+1);
            return (option1 || option2 || option3);
        }
        return false;
    }
    bool solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>>&dp){
        int m = a.length();
        int n = b.length();
        if(i == m && j == n) return dp[i][j] = true;
        if(i == m){
            bool flag = 1;
            for(int k=j; k<n; k++){
                if(b[k] != '*') flag = 0;
            }
            return dp[i][j] = flag;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j] || b[j] == '?'){
            return dp[i][j] = solveUsingMem(a, b, i+1, j+1, dp);
        }else if(b[j] == '*'){
            int option1 = solveUsingMem(a, b, i+1, j, dp);
            int option2 = solveUsingMem(a,b, i+1, j+1, dp);
            int option3 = solveUsingMem(a, b, i, j+1, dp);
            return dp[i][j] = (option1 || option2 || option3);
        }
        return dp[i][j] = false;
    }
    bool solveUsingTabulation(string &a, string& b){
        int m = a.length();
        int n = b.length();
        vector<vector<bool>>dp(m+1, vector<bool>(n+1, false));
        for(int i=m; i>=0; i--){
            for(int j=n; j>=0; j--){
                if(i == m && j == n) dp[i][j] = true;
                else if(i == m){
                    bool flag = 1;
                    for(int k=j; k<n; k++){
                        if(b[k] != '*') flag = 0;
                    }
                    dp[i][j] = flag;
                }
                else {
                    if(a[i] == b[j] || b[j] == '?'){
                        dp[i][j] = dp[i+1][j+1];
                    }else if(b[j] == '*'){
                        int option1 = dp[i+1][j];
                        int option2 = dp[i+1][j+1];
                        int option3 = dp[i][j+1];
                        dp[i][j] = (option1 || option2 || option3);
                    }
                }
            }
        }
        return dp[0][0];
    }
    bool solveUsingTabulationSO(string &a, string& b){
        int m = a.length();
        int n = b.length();
        // vector<vector<bool>>dp(m+1, vector<bool>(n+1, false));
        vector<bool>prev(n+1, false);
        vector<bool>curr(n+1, false);
        for(int i=m; i>=0; i--){
            for(int j=n; j>=0; j--){
                if(i == m && j == n) curr[j] = true;
                else if(i == m){
                    bool flag = 1;
                    for(int k=j; k<n; k++){
                        if(b[k] != '*') {
                            flag = 0;
                            break;
                        }
                    }
                    curr[j] = flag;
                }
                else {
                    if(a[i] == b[j] || b[j] == '?'){
                        curr[j] = prev[j+1];
                    }else if(b[j] == '*'){
                        int option1 = prev[j];
                        int option2 = prev[j+1];
                        int option3 = curr[j+1];
                        curr[j] = (option1 || option2 || option3);
                    }else {
                        curr[j] = false;
                    }
                }
            }
            prev = curr;
        }
        return curr[0];
    }
    bool isMatch(string s, string p) {
        // int m = s.length();
        // int n = p.length();
        // vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solveUsingTabulationSO(s, p);
    }
};