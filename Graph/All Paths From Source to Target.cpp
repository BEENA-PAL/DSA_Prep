// simple backtracking
// inert kro and remove krdo

class Solution {
    public:
        void dfs(int u, vector<int> &empty, vector<vector<int>> & ans, int n,vector<vector<int>>& adj){
            if(u == n -1) {
                ans.push_back(empty);
                return ;
            }
    
            for(auto v : adj[u]){
                empty.push_back(v);
                dfs(v,empty,ans,n,adj);
                empty.pop_back();
            }
        }
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<int> empty;
            empty.push_back(0);
            vector<vector<int>> ans;
    
            dfs(0,empty,ans,graph.size(),graph);
            return ans;
        }
    };