class Spreadsheet {
    vector<vector<int>> table;

public:
    Spreadsheet(int rows) {
        table.resize(rows + 1, vector<int>(26, 0)); // Resize properly
    }

    void setCell(string cell, int value) {
        int row = stoi(cell.substr(1)); // Extract row number
        int col = cell[0] - 'A'; // Convert letter to column index
        table[row][col] = value;
    }

    void resetCell(string cell) {
        int row = stoi(cell.substr(1));
        int col = cell[0] - 'A';
        table[row][col] = 0;
    }

    int getValue(string f) {
        // Check if it's a formula
        if (f[0] == '=') {
            f = f.substr(1); // Remove '=' sign

            stringstream ss(f);
            string token;
            int sum = 0;
            char op = '+'; // Default operator

            while (getline(ss, token, '+')) { // Splitting by '+'
                if (isdigit(token[0])) { 
                    sum += stoi(token); 
                } else { 
                    int col = token[0] - 'A';
                    int row = stoi(token.substr(1));
                    sum += table[row][col]; // Add cell value
                }
            }
            return sum;
        }

        int row = stoi(f.substr(1));
        int col = f[0] - 'A';
        return table[row][col];
    }
};
