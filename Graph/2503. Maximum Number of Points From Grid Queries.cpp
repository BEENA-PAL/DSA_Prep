//https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/?envType=daily-question&envId=2025-03-28

//------------------*************************-------------------------------
//        always keep visited arr to overcome infinite recursive call

//------------------*************************------------------------------

// brute force
class Solution {
    public:
    
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int arr[1000000];
    
    int findPoints(int i, int j, vector<vector<int>>& arr, int x, vector<vector<bool>>& visited) {
        int n = arr.size();
        int m = arr[0].size();
        
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j]   || arr[i][j] >= x)
            return 0;
        visited[i][j] = true;
        int cnt = 0;
        
        for (auto d : dir) {
            int i_ = i + d[0];
            int j_ = j + d[1];
            cnt += findPoints(i_, j_, arr, x, visited);
        }
        
        return cnt+1;
    }
       vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> ans;
        
        for (auto x : queries) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            vector<vector<bool>> dp(n, vector<bool>(m, false));
    
            int p = findPoints(0, 0, grid, x, visited);
            ans.push_back(p);
        }
        
        return ans;
    }
    };


    //----------------------**************************************----------------------------------

    //optimized

    