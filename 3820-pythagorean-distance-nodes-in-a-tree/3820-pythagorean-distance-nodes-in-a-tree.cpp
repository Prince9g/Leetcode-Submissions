class Solution {
public:
    void bfs(unordered_map<int,vector<int>>&adj, vector<int>&x, int src){
        queue<pair<int,int>>q;
        unordered_map<int,bool>vis;
        q.push({src, 0});
        vis[src]=true;
        while(!q.empty()){
            auto src = q.front();
            int node = src.first;
            int steps = src.second;
            x[node] = steps;
            q.pop();
            for(auto i: adj[node]){
                if(!vis[i]){
                    vis[i]=true;
                    q.push({i, steps+1});
                }
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        unordered_map<int,vector<int>>adj;
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>xx(n), yy(n), zz(n);
        bfs(adj, xx, x);
        bfs(adj, yy, y);
        bfs(adj, zz, z);
        int c = 0;
        for(int i=0; i<n; i++){
            vector<int>t;
            t.push_back(xx[i]);
            t.push_back(yy[i]);
            t.push_back(zz[i]);
            sort(t.begin(), t.end());
            if(1LL*t[0]*t[0] + 1LL*t[1]*t[1] == 1LL*t[2]*t[2]) c++;
        }
        return c;
    }
};