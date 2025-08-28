class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>>mapping;
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mapping[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &mp: mapping){
            if(mp.first >= 0){
                sort(mp.second.begin(), mp.second.end());
            }else{
                sort(mp.second.begin(), mp.second.end(), greater<int>());
            }
        }
        vector<vector<int>>ans(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = mapping[i-j].back();
                mapping[i-j].pop_back();
            }
        }
        return ans;
    }
};