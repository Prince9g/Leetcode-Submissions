class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int n = word.length();
        int temp = n - numFriends + 1;
        string ans = "";
        for(int i=0; i<n; i++){
            string ss = word.substr(i, temp);
            if(ss > ans){
                ans = ss;
            }
        }
        return ans;
    }
};