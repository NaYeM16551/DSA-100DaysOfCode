#include <bits/stdc++.h>

#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";
#define trav(i, v) for (auto &i : v)

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

vector<long long> leftSmaller(int n, long long a[],int x){
        // code here
        stack<long long> s;
        vector<long long> ans(n);
        int j=x;
        for(int i=0;i<n;++i)
        {
            if(!j)
              x=2*i;
           
            if(s.empty())
            {
                if(!j)
                  ans[x-i]=-1;
                else
                  ans[x-i]=n; 
            }
            else
            {
                while(!s.empty() && a[s.top()]>=a[x-i])
                  s.pop();
                  
                if(s.empty())
            {
                //ans[x-i]=j;
                if(!j)
                  ans[x-i]=-1;
                else
                  ans[x-i]=n;  
            }
            
            else
              ans[x-i]=s.top();
            }
            s.push(x-i);
         
            
        }
        return ans;
    }

    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
   
        auto leftAns=leftSmaller(n,arr,0);
        show(leftAns);
       
        auto rightAns=leftSmaller(n,arr,n-1);
        show(rightAns);
        
        long long  ans=INT_MIN;
        for(int i=0;i<n;++i)
        {
            leftAns[i]=max(rightAns[i]-leftAns[i]-1,0LL);
            long long area=arr[i]*leftAns[i];
            ans=max(ans,area);
            
        }
        return ans;
        
        
        
    }
int main()
{
    ifstream fin("input.txt");
   int n;
   fin>>n;
   long long arr[n];
   for(int i=0;i<n;++i)
     fin>>arr[i];
   cout<<getMaxArea(arr,n)<<endl;  
   cout<<"hello world!1222"<<endl;
   cout<<"exp nbranchr3r4t3454325"<<endl;
}
