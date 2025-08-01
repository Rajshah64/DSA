#include<bits/stdc++.h>

using namespace std; 

int main(){
    int n,m;
    cin>> n>>m;
    //int adj[n+1][m+1];
    //First we used adjacenct matrix to store the graph but it takes a lot of space .
    //Now we use adjacency list to store the graph which only takes space for the edges that are present.
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        //This is done for Unidirected graph.
    }

    //To store weighted graph , in matrix we directly store the weight in the matrix instead of 1.
    //In a adjacency list, we store pair of the node and the weight associated with it. 
    return 0;
}