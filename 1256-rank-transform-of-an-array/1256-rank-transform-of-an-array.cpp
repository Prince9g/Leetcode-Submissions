class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>>mapping;
        for(int i=0; i<arr.size(); i++){
            mapping.push_back({arr[i], i});
        }
        sort(mapping.begin(), mapping.end());
        int rank = 0;
        for(int i=0; i<arr.size(); i++){
            if(i==0 || mapping[i].first != mapping[i-1].first){
                rank++;
            }
            arr[mapping[i].second] = rank;
        }
        return arr;
    }
};