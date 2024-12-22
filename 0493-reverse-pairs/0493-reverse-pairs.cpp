class Solution {
public:
    int merge(vector<int>&nums, int p, int mid, int q){
        vector<int>temp;

        int count = 0, j = mid + 1;
        for (int i = p; i <= mid; i++) {
            while (j <= q && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - mid - 1);
        }
        int left = p;
        int right = mid+1;
        // int ans = 0;
        while(left <= mid && right <= q){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                // if(p < q) ans += (mid - p + 1);
                // if(nums[left] > 2* nums[right] && left <  right) ans += (mid - left + 1);
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= q){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=p; i<=q; i++){
            nums[i] = temp[i-p];
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int p, int q){
        if(p >= q) return 0;
        int mid = p + (q-p)/2;
        int ans = 0;
        ans += mergeSort(nums, p, mid);
        ans += mergeSort(nums, mid+1, q);
        ans += merge(nums, p, mid, q);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};