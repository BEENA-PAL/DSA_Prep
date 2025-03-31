//------------------------************************---------------------
// key take aways -> always look for empty string in any problem
//------------------------************************---------------------

// if(word1.size() == 0 and word2.size() == 0) return 0;
//if(word1.size() == 0 and word2.size()) return word2.size();
//if(word1.size() and word2.size() == 0) return word1.size();

class Solution
{
public:
    int dp[501][501];
    int solve(int i, int j, string &str1, string &str2)
    {
        if (i == str1.size() - 1 and j == str2.size() - 1)
        {
            return str1[i] == str2[j] ? 0 : 1;
        }
        else if (i == str1.size() and j < str2.size())
        {
            return str2.size() - j;
        }
        else if (i < str1.size() and j == str2.size())
        {
            return str1.size() - i;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (str1[i] == str2[j])
        {
            return dp[i][j] = solve(i + 1, j + 1, str1, str2);
        }
        else
        {
            return dp[i][j] = 1 + min({solve(i + 1, j, str1, str2), solve(i, j + 1, str1, str2), solve(i + 1, j + 1, str1, str2)});
        }
    }
    int minDistance(string word1, string word2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, word1, word2);
    }
};