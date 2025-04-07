//https : // leetcode.com/problems/partition-equal-subset-sum/?envType=daily-question&envId=2025-04-07

#include <iostream>
using namespace std;
#include<vector>

bool solve(int i, vector<int> &arr, int target)
{
    if (i >= arr.size() || target < 0)
    {
        if (target == 0)
            return true;
        return false;
    };
    bool take = solve(i + 1, arr, target - arr[i]);
    bool notTake = solve(i + 1, arr, target);
    return take | notTake;
}
bool solve(vector<int> &nums)
{
    int total = 0;
    for(auto & x:nums)total+=x;
    if (total % 2)
        return false;
    int target = total / 2;

    return solve(0, nums, target);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin>>tt;

    for(int t = 1; t <= tt; t++) {
        int n;
        cin>>n;
        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        bool ans = solve(arr);
        cout<<"#"<<t<<" "<<ans<<"\n";
    }
}