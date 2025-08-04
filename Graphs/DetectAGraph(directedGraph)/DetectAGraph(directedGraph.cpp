class Solution {
    private:
        bool dfs(int node, vetor<vector<int>>& adj,int vis[],int pathVis[] ){
            vis[node]=1;
            pathVis[node]=1;

            for(auto it : adj[node]){
                if(!vis[it]){
                    if(dfs(it, adj, vis, pathVis)){
                        return true;
                    }
                }
                // If the node has been previously visited but it has to be visited on the same path . 
                else if(pathVis[it]){
                    return true;
                }
            }
            pathVis[node]=0;
            return false;
        }
public:
    bool isCyclic(int V, vector<vector<int>>adj[]){
        int vis[V]={0};
        int pathVis[V]={0};

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};