class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPermutations(vector<int>& comp) {
        int c = 0;
        int n = comp.size();
        for(int i=1; i<n; i++){
            if(comp[0] >= comp[i]) c++;
        }
        if(c > 0) return 0;
        int ans = 1;
        for(int i=1; i<n; i++){
            ans = (1LL * ans * i)%MOD;
        }
        return ans;
    }
};