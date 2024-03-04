#include <bits/stdc++.h>
using namespace std;
vector<char> lcs;
int LCS(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
{
    if (!n || !m)
        return dp[n][m] = 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
    {
        lcs.push_back(s1[n - 1]);
        return dp[n][m] = 1 + LCS(s1, s2, n - 1, m - 1, dp);
    }

    else if (s1[n - 1] != s2[m - 1])
    {
        return dp[n][m] = max(LCS(s1, s2, n - 1, m, dp), LCS(s1, s2, n, m - 1, dp));
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << "Length of longest common substring: " << LCS(s1, s2, n, m, dp) << endl;

    for(auto& c : lcs)
       cout<<c<<endl;
    return 0;
}