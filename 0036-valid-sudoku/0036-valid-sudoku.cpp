class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();

    // Check each row
    for (int i = 0; i < rows; ++i) {
        unordered_set<char> isValidR; // Set for current row
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] != '.') {
                if (isValidR.find(board[i][j]) != isValidR.end()) {
                    return false; // Duplicate found in the same row
                } else {
                    isValidR.insert(board[i][j]);
                }
            }
        }
    }

    // Check each column
    for (int j = 0; j < cols; ++j) {
        unordered_set<char> isValidC; // Set for current column
        for (int i = 0; i < rows; ++i) {
            if (board[i][j] != '.') {
                if (isValidC.find(board[i][j]) != isValidC.end()) {
                    return false; // Duplicate found in the same column
                } else {
                    isValidC.insert(board[i][j]);
                }
            }
        }
    }

    // Check each 3x3 sub-grid
    for (int block = 0; block < 9; ++block) {
        unordered_set<char> blockSet; // Set for current 3x3 block
        int startRow = (block / 3) * 3;
        int startCol = (block % 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] != '.') {
                    if (blockSet.find(board[i][j]) != blockSet.end()) {
                        return false; // Duplicate found in the same 3x3 block
                    } else {
                        blockSet.insert(board[i][j]);
                    }
                }
            }
        }
    }

    return true;
}
};