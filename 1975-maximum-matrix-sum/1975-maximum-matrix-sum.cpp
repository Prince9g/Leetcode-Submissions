class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int small = 1e9;
        int c=0;
        long long sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                small = min(small, abs(mat[i][j]));
                if(mat[i][j] < 0){
                    c++;
                }
                sum += abs(mat[i][j]);
            }
        }
        if(c & 1){
            sum -= (small*2);
        }
        return sum;
    }
};