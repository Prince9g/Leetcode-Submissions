class Solution {
public:
    long long maximumHappinessSum(vector<int>& happy, int k) {
        int n = happy.size();
        long long c = 0;
        int m = 0;
        sort(happy.begin(), happy.end(), greater<int>());
        for(int i=0; i<k; i++){
            if(happy[i] - m > 0)
                c += happy[i] - m;
            m++;
        }
        return c;
    }
};