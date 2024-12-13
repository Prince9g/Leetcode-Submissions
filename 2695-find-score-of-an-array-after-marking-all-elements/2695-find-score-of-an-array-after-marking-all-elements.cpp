class Solution {
public:
    long long findScore(vector<int>& nums) {
        unordered_map<int, bool>visited;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i});
        }
        long long score=0;
        while(!pq.empty()){
            auto element = pq.top();
            pq.pop();
            int val = element.first;
            int index = element.second;
            if(visited.find(index) == visited.end()){
                score += val;
                visited[index] = true;
                if(index - 1 >= 0) visited[index-1] = true;
                if(index + 1 < nums.size()) visited[index+1] = true;
            }
        }
        return score;
    }
};