#include<bits/stdc++.h>
using namespace std;

bool IsGenerateInput(string& input, string& output)
{
    bool ans=false;
    if(output.size()> input.size())
      return ans;
    if(output.size()!=input.size() && output.find("*")==string::npos)
      return ans;
    string dummy=output;
    int j=0;
    for(int i=0;i<input.size();i++)
    {
      if(input[i]==output[j] || output[j]=='.')
        j++;
      else if(output[j]=='*')
        {
          
        }  
     

    }   
    return true;
}


int main() {
    string input,output;
    cin>>input>>output;

    cout<<boolalpha<<IsGenerateInput(input,output)<<endl;
    return 0;
}