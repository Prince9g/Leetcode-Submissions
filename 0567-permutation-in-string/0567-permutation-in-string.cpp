class Solution {
public:
//T.C = O(m+n) -> O(n)
//S.C = O(26) constant space
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        int i=0;
        int j=0;
        vector<int>s1_freq(26);
        vector<int>s2_freq(26);
        //store the frequency of the first string
        for(auto &ch: s1){
            s1_freq[ch - 'a']++;
        }
        while(j < n){
            s2_freq[s2[j] - 'a']++;
            if(j-i+1 > m){
                s2_freq[s2[i] - 'a']--;
                i++;
            }
            j++;
            if(s1_freq == s2_freq){
                return true;
            }
        }
        return false;
    }
};