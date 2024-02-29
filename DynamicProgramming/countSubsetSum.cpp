#include <iostream>
#include <vector>
using namespace std;

// loop way
int subsetCount(int arr[], int n, int sum)
{
    int t[n + 1][sum + 1];
    for (int i = 1; i < sum + 1; i++)
        t[0][i] = 0;

    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = (t[i - 1][j] + t[i - 1][j - arr[i - 1]]);
            else
                t[i][j] = t[i - 1][j];
        }

    return t[n][sum];
}

int subsetSumCountRecursiveMemo(int arr[], int n, int sum, vector<vector<int>> &memo)
{
    // Base cases
    if (sum == 0) // If sum becomes 0, then it means we have found a subset
        return 1;
    if (n == 0) // If no elements left but sum is still not 0, no subset possible
        return 0;

    // If the value is already calculated, return it from memoization
    if (memo[n][sum] != -1)
        return memo[n][sum];

    // If the last element is greater than the sum, ignore it
    if (arr[n - 1] > sum)
        memo[n][sum] = subsetSumCountRecursiveMemo(arr, n - 1, sum, memo);
    // Otherwise, check both including and excluding the last element
    else
        memo[n][sum] = subsetSumCountRecursiveMemo(arr, n - 1, sum, memo) +
                       subsetSumCountRecursiveMemo(arr, n - 1, sum - arr[n - 1], memo);

    return memo[n][sum];
}

int subsetSumCountMemoization(int arr[], int n, int sum)
{
    // Initialize memoization table with -1
    vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
    return subsetSumCountRecursiveMemo(arr, n, sum, memo);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    cout << "Count of subsets with sum " << sum << ": " << subsetSumCountMemoization(arr, n, sum) << endl;
    return 0;
}
