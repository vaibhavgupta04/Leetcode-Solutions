class Solution {
  public:
  void dfsH(int node,vector<int> &vis, vector<vector<int>>&adj,vector<int> &res){
      vis[node]=1;
      res.push_back(node);
      for(auto x:adj[node]){
          if(!vis[x]){
              dfsH(x,vis,adj,res);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> ans;
        vector<int> vis(n+1);
        dfsH(0,vis,adj,ans);
        return ans;
        
    }
};