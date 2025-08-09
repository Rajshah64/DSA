#include<bits/stdc++.h>

using namespace std;

//BFS method
class Solution{
    private:
        bool detect(int src, vector<vector<int>>& adj,int vis[]){
            vis[src]=1;
            queue<pair<int,int>> q;
            q.push({src,-1});
            while(!q.empty()){
                int node =q.front().first;
                int parent = q.front().second;
                q.pop();

                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push({it,node});
                    }
                    else if(parent!= it){
                        return true; // Cycle detected
                    }

                }
            }
            return false; // No cycle detected
        }
    public:
        bool isCycle(int V, vector<vector<int>>& adj){
            int vis[V]={0};
            for(int i=0; i<V;i++){
                if(!vis[i]){
                    if(detect(i,adj,vis)){ // If cycle is detected in the component
                        return true;
                    }
                }
            }
            return false; // No cycle detected in the graph
        } 
};


int main(){
    Solution sol;
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);
    // Add edges to the adjacency list
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[3].push_back(4);
    // Check for cycles
    if(sol.isCycle(V, adj)){
        cout << "Cycle detected in the graph" << endl;
    } else {
        cout << "No cycle detected in the graph" << endl;
    }
    //The solution of the given example is cycle detected
    return 0;
}