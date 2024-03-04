
#include <bits/stdc++.h>
using namespace std;

class Solution
{
int solve(vector<vector<int>> &dp, vector<vector<bool>> &selected, int price[], int n, int k) {
    if (n == 0 || k == 0)
        return 0;
        
    if (dp[n][k] != -1) 
        return dp[n][k];
        
    if (n >= k) {
        int include = price[k - 1] + solve(dp, selected, price, n - k, k);
        int exclude = solve(dp, selected, price, n, k - 1);
        
        if (include > exclude) {
            dp[n][k] = include;
            selected[n][k] = true; // Mark this piece as selected
        } else {
            dp[n][k] = exclude;
        }
    } else {
        dp[n][k] = solve(dp, selected, price, n, k - 1);
    }
        
    return dp[n][k];
}

public:
vector<int> getSelectedPieces(vector<vector<bool>> &selected, int n, int k) {
    vector<int> pieces;
    while (n > 0 && k > 0) {
        if (selected[n][k]) {
            pieces.push_back(k);
            n -= k;
        } else {
            --k;
        }
    }
    return pieces;
}

vector<int> getSelectedPiece(vector<vector<bool>> &selected, int n, int k) {
    vector<int> pieces;
    for(int n = 0; n < selected.size(); ++n) {
        for(int k=0;k<selected[n].size(); ++k) {
            if(selected[n][k])
              pieces.push_back(k);
        }
    }
    return pieces;
}



public:
int cutRod(int price[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<vector<bool>> selected(n + 1, vector<bool>(n + 1, false));
    int maxProfit = solve(dp, selected, price, n, n);
    vector<int> selectedPiece = getSelectedPiece(selected, n, n);
    
    cout << "Selected Pieces: ";
    for (int piece : selectedPiece) {
        cout << piece << " ";
    }
    cout << endl;
    
    return maxProfit;
}
};

//{ Driver Code Starts.

int main()
{
    int t;
    t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;

        
    }
    return 0;
}