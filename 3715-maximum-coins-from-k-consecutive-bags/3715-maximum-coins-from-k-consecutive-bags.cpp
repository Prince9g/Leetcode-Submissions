class Solution {
public:
    // long long maximumCoins(vector<vector<int>>& coins, int k) {
    //     vector<pair<int,int>>nums;
    //     int maxi = INT_MIN;
    //     for(auto it: coins){
    //         int diff = it[1] - it[0];
    //         maxi = max(maxi, it[1]);
    //         for(int i=0; i<=diff; i++){
    //             nums.push_back({it[0]+i , it[2]});
    //         }
    //     }
    //     long long ts = INT_MIN;
    //     long long current_sum = 0;
    //     sort(nums.begin(), nums.end());
    //     for (int i = 0; i <= maxi; ++i) {
    //     // Check if the pair with the first element i exists
    //     auto it = find_if(nums.begin(), nums.end(), [i](const pair<int, int>& p) {
    //         return p.first == i;
    //     });

    //     // If the pair does not exist, insert it
    //     if (it == nums.end()) {
    //         nums.push_back(make_pair(i, 0));
    //     }
    // }
    //     sort(nums.begin(), nums.end());
    //     int start = 0;
    //     for (int end = 0; end < nums.size(); ++end) {
    //         current_sum += nums[end].second;

    //         // If we have more than k elements, move the window
    //         if (end - start + 1 > k) {
    //             current_sum -= nums[start].second;
    //             start++;
    //         }

    //         // Update the maximum sum
    //         if (end - start + 1 == k) {
    //             ts = max(ts, current_sum);
    //         }
    //     }
    //     return ts;
    // }

long long maximumCoins(vector<vector<int>>& coins, int k) {
    long long res = 0, sum = 0;
    sort(begin(coins), end(coins));
    for (int i = 0, j = 0; i < coins.size(); ++i) {
        long long l = coins[i][0], r = coins[i][1], c = coins[i][2];
        sum += (r - l + 1) * c;
        while(r - k + 1 > coins[j][1]) {
            if (coins[j][0] + k - 1 >= l)
                res = max(res, sum - (r - (coins[j][0] + k - 1)) * c);
            sum -= ((long long)coins[j][1] - coins[j][0] + 1) * coins[j][2];
            ++j;
        }
        if (coins[j][0] + k - 1 >= r)
            res = max(res, sum);
        else {
            res = max(res, sum - (r - k + 1 - coins[j][0]) * coins[j][2]);
            if (coins[j][0] + k - 1 >= l)
                res = max(res, sum - (r - (coins[j][0] + k - 1)) * c);
        }
    }
    return res;
}



};






