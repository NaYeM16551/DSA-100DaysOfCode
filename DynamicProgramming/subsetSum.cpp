#include <bits/stdc++.h>


#define trav(i, v) for (auto &i : v)
#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

 bool is_subset_sum(const vector<int>&v,int n,vector<vector<bool>>&dp,int k)
{
  
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            if(v[j-1]<=j)
              dp[i][j]=dp[i-1][j-v[j-1]] || dp[i-1][j];
            else
             dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][k];


}
int main()
{

    ifstream fin("input2.txt");
    int n;
    fin>>n;
    vector<int> v(n);
    for(auto i = 0; i < n; i++)
     fin>>v[i];
    int k;
    fin>>k; 
     vector<vector<bool>> dp(n+1,vector<bool>(k+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;++j)
        {
           if(i==0)
             dp[i][j]=0;
           if(j==0)
             dp[i][j]=1;
        }
    }
    if(is_subset_sum(v,n,dp,k))
      cout<<boolalpha<<true<<endl;
     else
     cout<<false<<endl; 
}