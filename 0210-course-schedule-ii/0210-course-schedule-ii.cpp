class Graph{
    public:
    unordered_map<int,list<int>>adjList;
    
    void insert(int u, int v){
        adjList[u].push_back(v);
    }
    void topoOrdering(vector<int>&topoOrder){
        unordered_map<int, int>inDegree;
        for(auto mp: adjList){
            inDegree[mp.first] = 0;
        }
        for(auto mp: adjList){
            for(auto nbr: mp.second){
                inDegree[nbr]++;
            }
        }
        queue<int>q;
        for(auto mp: adjList){
            if(inDegree[mp.first] == 0) q.push(mp.first);
        }

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);
            for(auto nbr: adjList[frontNode]){
                inDegree[nbr]--;
                if(inDegree[nbr] == 0) q.push(nbr);
            }
        }
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& nums) {
        Graph g;
        for(auto i: nums){
            // if(!nums.empty())
                g.insert(i[1], i[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            g.adjList[i];
        }

        vector<int>topoOrder;
        g.topoOrdering(topoOrder);
        // reverse(topoOrder.begin(), topoOrder.end());
        if(topoOrder.size() != numCourses) return {};
        return topoOrder;
    }
};