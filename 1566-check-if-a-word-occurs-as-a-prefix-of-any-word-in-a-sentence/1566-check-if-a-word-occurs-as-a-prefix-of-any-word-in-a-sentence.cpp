class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        stringstream ss(s);
        string word;
        int i=0;
        while(getline(ss, word, ' ')){
            i++;
            if(word.substr(0,w.length()) == w){
                return i;
            }
        }
        return -1;
    }
};