class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(s.find(part) == string :: npos){
            return s;
        }
        //recursive relation
        s.erase(s.find(part),part.length());
        string rec = removeOccurrences(s, part);
        return rec;
    }
};