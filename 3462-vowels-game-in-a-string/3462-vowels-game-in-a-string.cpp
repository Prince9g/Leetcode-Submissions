class Solution {
public:
    bool doesAliceWin(string s) {
        int vowel=0;
        for(auto i: s) {
            if(i == 'a' || i=='e' || i=='i' || i=='o' || i=='u'){
                vowel++;
            }
        }
        if(vowel==0) return false;
        return true;
    }
};