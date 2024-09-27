class Solution {
public:
    bool solve(vector<int>&nums, int s, int e, int p1, int p2, bool isPlayer1){
        if(s > e){
            return p1 >= p2;
        }
        //logic
        if(isPlayer1){
            return solve(nums, s+1, e, p1 + nums[s], p2, false) ||
                solve(nums, s, e-1, p1 + nums[e], p2, false);
        }else{
            //player2 turn
             return solve(nums, s+1, e, p1, p2 + nums[s], true) &&
                solve(nums, s, e-1, p1, p2 + nums[e], true);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1, 0, 0, true);
    }
};