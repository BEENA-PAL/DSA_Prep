#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> &arr)
{

    // if rot length is nothing that mean that it will cost nothing

    if (n == 0)
    {
        return 0;
    }

    // now partitioning the rod at every length and finding the maximum cost out of it

    // { 1,| 5, 8, 9, 10, 17, 17, 20};
    // { 1, 5,| 8, 9, 10, 17, 17, 20};
    // { 1, 5, 8, | 9, 10, 17, 17, 20};
    // { 1, 5, 8, 9, 10,| 17, 17, 20};
    // { 1, 5, 8, 9, 10, 17, | 17, 20};
    // { 1, 5, 8, 9, 10, 17, 17, |20};

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int remainingLen = n - i;
        int cost = arr[i - 1] + solve(remainingLen, arr);
        ans = max(ans, cost);
    }
    return ans;
}

int rod_cut(vector<int> &arr)
{
    int len = arr.size();

    return solve(len, arr);
}
int main()
{

    vector<int> arr = {1, 5, 8, 9, 10, 17, 17, 20};
    int ans = rod_cut(arr);
    cout << ans << endl;
    return 0;
}