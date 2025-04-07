#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> solve(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<pair<int, int>> preSum(n + 1);

    preSum[0].first = 0;
    preSum[0].second = 0;

    for (int i = 1; i <= n; i++)
    {
        int preAdd = preSum[i - 1].first;
        int prePower = preSum[i - 1].second;

        preAdd += arr[i - 1];
        prePower += arr[i - 1] * arr[i - 1];

        preSum[i].first = preAdd;
        preSum[i].second = prePower;
    }

    unordered_map<string, vector<int>> mp;

    for (int i = k; i <= n; i++)
    {
        int addDiff = preSum[i].first - preSum[i - k].first;
        int powerDiff = preSum[i].second - preSum[i - k].second;

        string mask = to_string(addDiff) + to_string(powerDiff);
        mp[mask].push_back(i-k);
    }

    vector<int> ans(n-k+1);

    for(auto x : mp){
        for(auto index:x.second){
            ans[index] = x.second.size();
        }
    }
    return ans;
}


int main()
{
    int tt;
    cin >> tt;

    for (int t = 1; t <= tt; t++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);

        for (auto &x : arr)
        {
            cin >> x;
        }

        vector<int> ans = solve(arr, k);

        for (auto &x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

