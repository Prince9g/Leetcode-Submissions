class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int>zeroes(n), ones(n);
        s[0] == '0' ? zeroes[0] = 1 : zeroes[0] = 0;
        s[n-1] == '1' ? ones[n-1] = 1 : ones[n-1] = 0;
        for(int i=1; i<n; i++){
            zeroes[i] = zeroes[i-1] + (s[i] == '0' ? 1 : 0);
        }
        for(int i=n-2; i>=0; i--){
            ones[i] = ones[i+1] + (s[i] == '1' ? 1 : 0);
        }
        int maxCount = INT_MIN;
        for(int i=0; i<n-1; i++){
            int count = zeroes[i] + ones[i+1];
            if(count > maxCount){
                maxCount = count;
            }
        }
        return maxCount;
    }
};