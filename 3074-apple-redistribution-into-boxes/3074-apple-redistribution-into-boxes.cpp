class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int sum = accumulate(apple.begin(), apple.end(), 0);
        int t = 0;
        int tSum = 0;
        for(auto i: capacity){
            tSum += i;
            t++;
            if(tSum >= sum) break;
        }
        return t;
    }
};