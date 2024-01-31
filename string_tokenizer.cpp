#include<bits/stdc++.h>
using namespace std;

vector<int> tokenize(std::string const &str, const char delim)
{
    // construct a stream from the string
    std::stringstream ss(str);
    std::vector<int> out;

    std::string s;
    while (std::getline(ss, s, delim)) {
        if(!s.empty())
          out.push_back(stoi(s));
    }
    return out;

}
