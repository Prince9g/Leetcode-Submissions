class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;           // Start with the first line
        int lastLineSize = 0;    // Size of the last line
        
        for (auto ch : s) {
            int width = widths[ch - 'a']; // Get the width of the character
            
            if (lastLineSize + width > 100) {
                // If adding this character exceeds the limit, move to the next line
                lines++;
                lastLineSize = width; // Start the new line with this character
            } else {
                // Add the character to the current line
                lastLineSize += width;
            }
        }
        
        return {lines, lastLineSize};
    }
};
