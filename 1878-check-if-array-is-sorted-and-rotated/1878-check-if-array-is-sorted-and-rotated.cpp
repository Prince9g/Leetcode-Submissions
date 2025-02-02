class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i=n-1;
        // int index=-1;
        while(i-1 >= 0 && nums[i - 1] <= nums[i]){
            i--;
        }
        cout << i << endl;
        for(int j=0; j<n-1; j++){
            if(nums[(i+j) % n] > nums[(i+j+1)%n]) return false;
        }
        return true;
    }
};