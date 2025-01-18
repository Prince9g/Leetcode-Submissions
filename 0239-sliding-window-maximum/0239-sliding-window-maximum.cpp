class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>ans;
        //process first window of k size
        for(int i=0; i<k; i++){
            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        //process remaining window
        int n = nums.size();
        ans.push_back(nums[q.front()]);
        for(int i=k; i<n; i++){
            //remove the outside window elements
            if(i - k >= q.front()){
                q.pop_front();
            }
            //remove min element
            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};