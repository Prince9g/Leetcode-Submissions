class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        vector<int> ans;
        int n = digits.size();
        int carry = 1;
        int index = 0;
        while(index < n){
            int totalSum = digits[index] + carry;
            int digit = totalSum % 10;
            carry = totalSum/10;
            ans.push_back(digit);
            index++;
            // if(carry == 0){
            //     break;
            // }
        }
      if(carry != 0){
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};