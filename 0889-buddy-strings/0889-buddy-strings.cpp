class Solution {
public:
    bool buddyStrings(string s, string goal) {
    int n = s.length();
    if (n != goal.length()) return false; // Lengths must match

    int index = -1;

    // Find the first mismatching index
    for(int i = 0; i < n; i++) {
        if(s[i] != goal[i]) {
            index = i;
            break;
        }
    }

    // Case when both strings are the same
    if(s == goal) {
        unordered_set<char> st(s.begin(), s.end());
        if(n > st.size()) return true; // Check if there is any duplicate character
        return false;
    }

    if(index == -1) return false; // If no mismatches were found, they can't be buddy strings

    // Attempt to swap characters
    for(int i = index + 1; i < n; i++) {
        if(s[index] == goal[i] && s[i] == goal[index]) {
            swap(s[index], s[i]);
            return s == goal;
        }
    }
    
    return false;
}


};