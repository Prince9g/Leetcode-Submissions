class Solution {
public:
    bool solve(int num, int index, int currSum, string s){
        if(index >= s.length()){
            return currSum == num;
        }
        if(currSum > num) return false;
        bool isPossible = false;
        for(int i=index; i<s.length(); i++){
            string temp = s.substr(index, i-index+1);
            int number = stoi(temp);
            isPossible = solve(num, i+1, currSum+number, s);
            if(isPossible) return true;
        }
        return isPossible;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++){
            int num = i*i;
            string s = to_string(num);
            if(solve(i, 0, 0, s)) ans += num;
        }
        return ans;
    }
};