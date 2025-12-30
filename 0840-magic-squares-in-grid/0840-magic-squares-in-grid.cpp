class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        vector<int> counts(10, 0);
        int sum1 = 0, sum2 = 0;
        
        // Check the rows and count occurrences of digits
        for (int i = 0; i < 3; ++i) {
            sum1 = sum2 = 0;
            for (int j = 0; j < 3; ++j) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || ++counts[num] > 1) return false;
                sum1 += grid[r + i][c + j];
                sum2 += grid[r + j][c + i];
            }
            if (sum1 != 15 || sum2 != 15) return false;
        }
        
        // Check diagonals
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15) return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15) return false;
        
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (grid[i + 1][j + 1] != 5) continue; // middle of magic square must be 5
                if (isMagic(grid, i, j)) ++count;
            }
        }
        
        return count;
    }
};