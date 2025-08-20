// Problem number 785 on leetcode .

// this is the dfs approach
//  class Solution
//  {
//      private:
//          bool dfs(vector<vector<int>>& graph, vector<int>& color, int node , int col){
//              color[node]=col;
//              for(auto it: graph[node]){
//                  if(color[it]==-1){
//                      if(!dfs(graph,color,it, !col)){
//                          return false;
//                      }

//                 }else if(color[it]==col){
//                         return false;
//                     }
//             }
//             return true;
//         }
//     public:
//     bool isBipartite(vector<vector<int>> &graph){
//         int n=graph.size();
//         vector<int> color(n,-1);
//         bool ans;
//         for(int i=0;i<n;i++){
//             if(color[i]==-1){
//                 if (!dfs(graph, color, i, 0)) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

// This is the bfs approach
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++)
        {
            if (color[start] == -1)
            {
                queue<int> q;
                q.push(start);
                color[start] = 0;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (auto it : graph[node])
                    {
                        if (color[it] == -1)
                        {
                            color[it] = !color[node];
                            q.push(it);
                        }
                        else if (color[it] == color[node])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
