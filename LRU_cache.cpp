#include <bits/stdc++.h>
#include "headerFile/test.h"

#define show(v)                  \
    trav(i, v) cout << i << " "; \
    cout << "\n";
#define trav(i, v) for (auto &i : v)

#define watch(x) cerr << #x << " = " << x << "\n"
extern ofstream out11;
extern string st;
using namespace std;

class LRU_cache
{
private:
    class Doubly_linkedList
    {
    private:
        class Node
        {

        public:
            Node *next;
            Node *prev;
            pair<int, int> key_value;

            explicit Node(pair<int, int> key_value)
            {
                this->key_value = key_value;
                this->next = nullptr;
                this->prev = nullptr;
            }
        };
        Node *head;
        Node *tail;
        unordered_map<int, Node *> mp;
        int max_size;
        int size;

    public:
        Doubly_linkedList()
        {
            this->head = new Node({-1, -1});
            this->tail = new Node({-1, -1});
            head->next = tail;
            tail->prev = head;
            this->size = 0;
        }

        void set_max_size(int max_size)
        {
            this->max_size = max_size;
        }

        void delete_node(int key)
        {
            if (mp.find(key) != mp.end())
            {
                Node *node = mp[key];
                mp.erase(key);
                Node *tail_pointer = node->next;
                Node *node_before = node->prev;
                tail_pointer->prev = node_before;
                node_before->next = tail_pointer;
                delete node;
            }
        }
        int get_value(int key)
        {
            if (mp.find(key) == mp.end())
                return -1;
            else
            {
                Node *node = mp[key];
                auto key_value = node->key_value;
                delete_node(key);
                insert_helper(key_value);
                return key_value.second;
            }
        }

    private:
        void insert_helper(pair<int, int> key_value)
        {
            Node *temp = head->next;
            Node *newNode = new Node(key_value);
            head->next = newNode;
            newNode->prev = head;
            temp->prev = newNode;
            newNode->next = temp;
            mp[key_value.first] = newNode;
        }

    public:
        void insert_node(pair<int, int> key_value)
        {
            int key = key_value.first;
            int value = key_value.second;
            bool not_exist = mp.find(key) == mp.end();
            if (not_exist && size < max_size)
            {
                insert_helper(key_value);
                size++;
            }
            else if (not_exist && size >= max_size)
            {
                Node *second_last_node = tail->prev->prev;
                int key = tail->prev->key_value.first;
                mp.erase(key);
                delete tail->prev;
                second_last_node->next = tail;
                tail->prev = second_last_node;
                insert_helper(key_value);
                size++;
            }
            else if (!not_exist)
            {
                delete_node(key);
                insert_helper(key_value);
            }
        }
    };

  
    Doubly_linkedList dll;

public:
    explicit LRU_cache(int max_size)
    {
     
        dll.set_max_size(max_size);
    }

    void put(int key, int value)
    {
        pair<int, int> p(key, value);
        dll.insert_node(p);
    }

    int get(int key)
    {
        return dll.get_value(key);
    }
};


class LRU_cache_list
{
private:
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cache_map;
    int capacity;

public:
    explicit LRU_cache_list(int capacity) : capacity(capacity)
    {
    }

    int get(int key)
    {
        if (cache_map.find(key) == cache_map.end())
            return -1;

        auto node = cache_map[key];
        cacheList.splice(cacheList.begin(), cacheList, node);
        cache_map[key] = cacheList.begin();
        return cacheList.front().second;
    }

    void put(int key, int value)
    {
        bool not_exist = cache_map.find(key) == cache_map.end();
        if (!not_exist)
        {
            cacheList.splice(cacheList.begin(), cacheList, cache_map[key]);
             cache_map[key] = cacheList.begin();
            cache_map[key] = cacheList.begin();
        }
        else
        {
            if (cache_map.size() >= capacity)
            {
                int least_recently_used_key = cacheList.back().first;
                cacheList.pop_back();
                cache_map.erase(least_recently_used_key);
            }
            cacheList.emplace_front(key, value);
            cache_map[key] = cacheList.begin();
        }
    }
};

int dummy(int a,int b)
{
    out11<<"hello beuddy in funcFoo"<<endl;
    st+=" I love you!";
    out11<<st<<endl;
    return a+b;
}
/* int main()
{

    /* LRU_cache LRU(2);

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
  out1<<"hello world from LRU"<<endl;

} */