class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto p: piles){
            pq.push(p);
        }
        // if(k > piles.size()) return 
        while(k--){
            int ele = ceil((float)pq.top()/2);
            pq.pop();
            pq.push(ele);
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};