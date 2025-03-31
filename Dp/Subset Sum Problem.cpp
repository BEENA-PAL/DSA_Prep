//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    // bool solve(int i, vector<int>& arr, int target) {
    //     if(i == arr.size())return false;
    //     if(target == 0) return true;
    //     if(target < 0) return false;
        
    //     bool take = solve(i+1,arr, target - arr[i]);
    //     if(take) return true;
        
    //     bool notTake = solve(i+1, arr, target);
    //     if(notTake) return true;
        
    //     return take | notTake;
    // }
    bool isSubsetSum(vector<int>& arr, int target) {
        
        int n = arr.size();
        bool dp[n+1][target+1];
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for(int i = 1; i <= target; i++) {
            dp[0][i] = false;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                int pre = j - arr[i-1];
                if(pre >= 0) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][pre];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    
        return dp[n][target];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
