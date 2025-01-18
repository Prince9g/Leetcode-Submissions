class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        //process first k elements from the array
        for(int i=0; i<k; i++){
            int element = nums[i];
            //removal of minimum numbers besides element
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            //push the maximum element index in the queue
            dq.push_back(i);
        }

        //now the turn for removals and process other windows of array
        for(int i=k; i<nums.size(); i++){
            ans.push_back(nums[dq.front()]);
            int element = nums[i];
            //removal of out of bound
            if(i - dq.front() >= k){
                dq.pop_front();
            }
            //removal of not maximums
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            //addition
            dq.push_back(i);
        }

        //last window ko process krdo
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};