class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char first, second;
        int maxPoints, minPoints;
        
        // Determine the order of operations based on the points
        if (x > y) {
            first = 'a';
            second = 'b';
            maxPoints = x;
            minPoints = y;
        } else {
            first = 'b';
            second = 'a';
            maxPoints = y;
            minPoints = x;
        }

        auto removePairs = [&](char first, char second, int points) {
            std::stack<char> stack;
            int score = 0;
            
            for (char c : s) {
                if (!stack.empty() && stack.top() == first && c == second) {
                    stack.pop();
                    score += points;
                } else {
                    stack.push(c);
                }
            }
            
            std::string remaining;
            while (!stack.empty()) {
                remaining.push_back(stack.top());
                stack.pop();
            }
            std::reverse(remaining.begin(), remaining.end());
            s = remaining;
            
            return score;
        };

        // Remove the substring with maximum points first
        int totalScore = removePairs(first, second, maxPoints);

        // Remove the remaining substring
        totalScore += removePairs(second, first, minPoints);

        return totalScore;
    }
};