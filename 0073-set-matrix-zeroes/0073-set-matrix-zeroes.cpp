class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // //better appproach 
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<int>rows(m, -1);
        // vector<int>cols(n, -1);
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(matrix[i][j] == 0) rows[i] = 0;
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(matrix[j][i] == 0) cols[i] = 0;
        //     }
        // }
        // // for(auto i: cols) cout << i << " ";
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(rows[i] == 0 || cols[j] == 0){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }



        //best approach now 
        int col1 = 1;
        //taking first row and first col as the two vecctors that wwe took as in better approach to optimize space complexity
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0) matrix[0][j] = 0;
                    else col1 = 0;
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int i=0; i<n; i++){
                matrix[0][i] = 0;
            }
        }
        if(col1 == 0){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};