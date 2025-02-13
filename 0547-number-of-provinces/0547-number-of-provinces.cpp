class Solution {
public:
    void dfs(int src, int v, vector<vector<int>>& isConnected, unordered_map<int,bool>&visited){
        visited[src] = true;
        int col = v;
        for(int i=0; i<col; i++){
            int nbr = i;
            if(src != nbr && isConnected[src][nbr]==1){
                if(!visited[i]){
                    dfs(nbr, v, isConnected, visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool>visited;
        int n = isConnected.size();
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, n, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};