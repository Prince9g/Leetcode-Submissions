class compare{
    public:
    bool operator()(pair<char,int>&a, pair<char,int>&b){
        return a.second < b.second;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char,int>, vector<pair<char,int>>, compare>pq;
        if(a != 0)
            pq.push({'a',a});
        if(b != 0)
            pq.push({'b',b});
        if(c != 0)
            pq.push({'c',c});
        string ans = "";
        while(pq.size() > 1){
            auto temp = pq.top();
            pq.pop();
            if(temp.second >= 2){
                ans.push_back(temp.first);
                ans.push_back(temp.first);
                temp.second -= 2;
            }else{
                ans.push_back(temp.first);
                temp.second--;
            }
            if(!pq.empty()){
                auto tempu = pq.top();
                pq.pop();
                if(tempu.second >= 2 && tempu.second >= temp.second){
                    ans.push_back(tempu.first);
                    ans.push_back(tempu.first);
                    tempu.second -= 2;
                }else{
                    ans.push_back(tempu.first);
                    tempu.second--;
                }
                if(tempu.second > 0) pq.push({tempu.first, tempu.second});
            }
            if(temp.second > 0) pq.push({temp.first, temp.second});
        }
        if(!pq.empty()){
            if(pq.top().second >= 2){
                ans.push_back(pq.top().first);
                ans.push_back(pq.top().first);
            }else{
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};