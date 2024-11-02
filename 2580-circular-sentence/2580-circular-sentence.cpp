class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        vector<string>words;
        string word;
        while(getline(ss, word, ' ')){
            words.push_back(word);
        }
        for(int i=0; i<words.size(); i++){
            string str = words[i];
            if(str[str.length()-1] != words[(i+1)%words.size()][0]){
                return false;
            }
        }
        return true;
    }
};