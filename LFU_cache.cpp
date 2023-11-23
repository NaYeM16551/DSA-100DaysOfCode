#include <bits/stdc++.h>

#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";
#define trav(i, v) for (auto &i : v)

#define watch(x) cerr << #x << " = " << x << "\n"
using namespace std;

class LFU_cache
{
private:
    unordered_map<int, list<pair<int,pair<int,int>>>> frequency_list;      // freq : list(key,value,freq)
    unordered_map<int, list<pair<int,pair<int,int>>>::iterator> cache_map; // key : list iterator
    int least_frequency;
    int capacity;

public:
    explicit LFU_cache(int capacity)
    {
        this->capacity = capacity;
        this->least_frequency=0;
    }

    int get(int key)
    {
        if (cache_map.find(key) == cache_map.end())
            return -1;

        auto node = cache_map[key];
        int freq = node->second.second;
        int value = node->second.first;
       
        frequency_list[freq].erase(node);
         cache_map.erase(key);
        freq++;
        frequency_list[freq].emplace_front(key,value, freq);
        cache_map[key] = frequency_list[freq].begin();
        if (frequency_list[least_frequency].empty())
            least_frequency++;
        return frequency_list[freq].front().first;
    }

    void put(int key, int value)
    {
        bool not_exist=cache_map.find(key)==cache_map.end();

        if(!not_exist)
        {
            cache_map[key]->first=value;
            get(key);
            return;
        }
        else
        {
            if(cache_map.size()>=capacity)
            {
                auto least_frequently_used_node=(frequency_list[least_frequency].back().first);
                frequency_list[least_frequency].erase(cache_map[least_frequently_used_node]);
                cache_map.erase(least_frequently_used_node);

            }

            frequency_list[1].push_front({key,{value,1}});
            cache_map[key]=frequency_list[1].begin();
            least_frequency=1;
        }
    }
};


int main() {
   LFU_cache LRU(2);
   //ifstream fin("input.txt");
   
    while (true)
    {
        char inp;
        cin >> inp;
        if (inp == 'p')
        {
            int key, value;
            cin >> key >> value;
            LRU.put(key, value);
        }
        else if (inp == 'g')
        {
            int key;
            cin >> key;
            cout << LRU.get(key) << endl;
        }
        else
            break;
    }

    return 0;
}