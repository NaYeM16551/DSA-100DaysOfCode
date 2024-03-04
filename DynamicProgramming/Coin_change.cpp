#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int solve(vector<int> &coins, vector<vector<int>> &dp, int n, int target)
{
  if (!target)
    return dp[n][target]=0;
  if (!n || target < 0)
    return dp[n][target]=INT_MAX - 1;
  if (dp[n][target] != -1)
    return dp[n][target];
  if (coins[n - 1] <= target)
    dp[n][target] = min(1 + solve(coins, dp, n, target - coins[n - 1]), solve(coins, dp, n - 1, target));
  else
    dp[n][target] = solve(coins, dp, n - 1, target);
  return dp[n][target];
}

int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    int ans = solve(coins, dp, n, target);
    if (ans > INT_MAX - 2) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}
