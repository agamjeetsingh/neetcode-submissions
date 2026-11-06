class LRUCache {
public:
    LRUCache(int capacity): capacity(capacity) {
        
    }
    
    int get(int key) {
        if (!mp.contains(key)) {
            return -1;
        }
        auto it = mp[key];
        int val = it->second;
        values.erase(it);
        values.push_back({key, val});
        mp[key] = prev(values.end());

        return val;
    }
    
    void put(int key, int value) {
        if (!mp.contains(key)) {
            values.push_back({key, value});
            mp[key] = prev(values.end());
            if (++size > capacity) {
                auto it = values.begin();
                mp.erase(it->first);
                values.erase(it);
                size--;
            }
        } else {
            get(key);
            *prev(values.end()) = {key, value};
        }
    }

    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> values;
    int capacity;
    int size = 0;
};
