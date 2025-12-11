class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
         map<int, set<int>> rows, cols;
    
    for (auto& b : buildings) {
        int x = b[0], y = b[1];
        rows[x].insert(y);
        cols[y].insert(x);
    }
    
    int count = 0;
    
    for (auto& b : buildings) {
        int x = b[0], y = b[1];
        
        bool hasLeft = false, hasRight = false, hasAbove = false, hasBelow = false;
        
        // Check left (any y' < y in same row x)
        auto it = rows[x].lower_bound(y);
        if (it != rows[x].begin()) hasLeft = true;
        
        // Check right (any y' > y in same row x)
        it = rows[x].upper_bound(y);
        if (it != rows[x].end()) hasRight = true;
        
        // Check above (any x' < x in same column y)
        auto it2 = cols[y].lower_bound(x);
        if (it2 != cols[y].begin()) hasAbove = true;
        
        // Check below (any x' > x in same column y)
        it2 = cols[y].upper_bound(x);
        if (it2 != cols[y].end()) hasBelow = true;
        
        if (hasLeft && hasRight && hasAbove && hasBelow) {
            count++;
        }
    }
    
    return count;
    }
};