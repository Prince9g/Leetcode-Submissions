class Info{
    public:
    float val;
    int x;
    int y;
};

class compare{
    public:
    bool operator()(Info a, Info b){
        return a.val > b.val;
    }
};

class Solution {
public:
    float findSqrt(int a, int b){
        return sqrt(a*a + b*b);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Info, vector<Info>, compare>pq;
        for(auto po : points){
            float sq = findSqrt(po[0], po[1]);
            pq.push({sq, po[0], po[1]});
        }
        vector<vector<int>>ans;
        while(k--){
            if(!pq.empty()){
                ans.push_back({pq.top().x, pq.top().y});
                pq.pop();
            }
        }
        return ans;
    }
};