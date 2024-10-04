class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long sum = 0;
        int s = 0;
        int e = skill.size() -1;
        int tsum = skill[s] + skill[e];
        while(s < e){
            if(skill[s] + skill[e] != tsum){
                return -1;
            }
            sum = sum +  skill[s] * skill[e];
            s++; e--;
        }
        return sum;
    }
};