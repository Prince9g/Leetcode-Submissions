class Solution {
public:
#define ll long long 
vector<ll>dp;
ll f(vector<pair<ll,ll>>&vec, ll i){
    int n = vec.size();
    if(i >= n) return 0;
    ll inc=0,exc=0;
    if(dp[i] != -1) return dp[i];
    int j=i;
    while(j < n && vec[j].first - vec[i].first <= 2) j++;
    inc = vec[i].first*vec[i].second + f(vec, j);
    exc = f(vec, i+1);
    return dp[i] = max(inc,exc);
}
    long long maximumTotalDamage(vector<int>& power) {
        map<ll,ll>freq;
        for(auto i: power){
            freq[i]++;
        }
        vector<pair<ll,ll>>vec;
        for(auto i: freq){
            vec.push_back(i);
        }
        dp.resize(vec.size()+1, -1);
        return f(vec, 0);
    }
};