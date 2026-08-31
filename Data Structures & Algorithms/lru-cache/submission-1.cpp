class LRUCache {
public:
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.contains(key)) {
            auto it = mp.at(key);
            int val = it->second;
            lru.erase(it);
            lru.push_back({key, val});
            mp[key] = prev(lru.end());
            return val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mp.contains(key)) {
            lru.erase(mp.at(key));
        } else if (lru.size() == capacity) {
            auto it = lru.begin();
            int k = it->first;
            lru.erase(it);
            mp.erase(k);
        }
        lru.push_back({key, value});
        mp[key] = prev(lru.end());
    }
};
