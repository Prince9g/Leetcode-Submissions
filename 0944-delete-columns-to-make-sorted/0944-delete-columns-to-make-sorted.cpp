class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int c=0;
        for(int i=0; i<strs[0].length(); i++){
            vector<char>t;
            for(int j=0; j<n; j++){
                t.push_back(strs[j][i]);
            }
            vector<char>m = t;
            sort(m.begin(), m.end());
            if(t != m) c++;
        }
        return c;
    }
};