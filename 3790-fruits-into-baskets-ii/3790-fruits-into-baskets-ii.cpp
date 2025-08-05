class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<pair<int,bool>>pairs;
        int n = baskets.size();
        for(auto i: baskets){
            pairs.push_back({i, false});
        }
        for(auto i: fruits){
            for(int j=0; j<n; j++){
                if(pairs[j].second == false && pairs[j].first >= i){
                    pairs[j].second = true;
                    break;
                }
            }
        }
        int unplace = 0;
        for(auto i: pairs){
            if(!i.second) unplace++;
        }
        return unplace;
    }
};