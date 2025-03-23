//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/?envType=daily-question&envId=2025-03-23

class Solution {
    public:
    
    // idea
    // u pe pahuchne me jitne tareeke se pahucha ja skta hai utne ki tareeke se v pe bhi pahuchaa ja skta hai
    // starting me ->  src pe phuchne ka ek tareeka hai
    // mtlb 0 pe hai or 0 pe hi pahuchna hai to uske liye ek tareeka hoga
    // 0 ---> 1 pe jana hai to 1 tak pahuchne ka bhi ek hi tareeka hoga qki 0 tk pahuchne ka ek hi tareeka hai
    // suppose agar hm jaise taise node 3 pe hai or vahaa tk pahuchne k 2 tareeke hai or there is edge like 3 ----> 4 then the 4 pe bhi pahuchne k 2 hi tareeke honge
    
    // agar naya wt chhota mil rha hai to ham use append kr denge or jitna u tk aane k ways honge utne ki v tk bhi ane k honge
    
    long long MOD = 1e9 + 7;
        int countPaths(int n, vector<vector<int>>& roads) {
    
            vector<vector<vector<long long>>> adj(n);
            for(auto edge : roads) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
    
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
    
            priority_queue<vector<long long>,vector<vector<long long>>, greater<vector<long long>>> q;
            vector<long long> distance(n,LLONG_MAX);
            vector<long long> cnt(n,0);
    
    
            q.push({0,0});
            distance[0]=0;
            cnt[0] = 1;
    
            while(!q.empty()) {
                long long wt = q.top()[0];
                long long u = q.top()[1];
                q.pop();
    
                for(auto edge : adj[u]){
                    long long v = edge[0];
                    long long nWt = edge[1];
    
                    long long totalWt = wt + nWt;
    
                    if(totalWt < distance[v]){
                        distance[v] = totalWt;
                        q.push({ distance[v],v});
                        cnt[v] = cnt[u];
                    }else if(totalWt == distance[v]) {
                       cnt[v] =( cnt[v] +  cnt[u]) %(MOD);
                    }
                }
            }
    
            return cnt[n-1];
        }
    };