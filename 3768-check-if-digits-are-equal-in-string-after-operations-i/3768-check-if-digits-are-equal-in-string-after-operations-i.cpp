class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        string temp = "";
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < s.length()-1; j++) {
                int num = (s[j] - '0' + s[j+1] - '0') % 10;
                temp.push_back(num + '0');
            }
            if(temp.length() == 2){
                if(temp[0] == temp[temp.length()-1]) return true;
                else return false;
            }
            s = temp;
            temp.clear();
        }
        return false;
    }
};