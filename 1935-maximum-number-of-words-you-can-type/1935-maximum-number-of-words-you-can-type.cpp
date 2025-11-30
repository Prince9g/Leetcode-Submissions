class Solution {
public:
    int canBeTypedWords(string text, string b) {
        stringstream ss(text);
        string data;
        int c=0;
        int known=0;
        while(getline(ss, data, ' ')){
            known++;
            for(auto i: b){
                if(data.find(i) != string::npos){
                    c++;
                    break;
                }
            }
        }
        return known-c;
    }
};