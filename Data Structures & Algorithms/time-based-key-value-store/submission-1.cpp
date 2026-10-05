class TimeMap {
public:
    TimeMap() {
        
    }

    unordered_map<string, map<int, string>> data;
    
    void set(string key, string value, int timestamp) {
        data[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = data[key].upper_bound(timestamp);
        return it == data[key].begin() ? "" : prev(it)->second;
    }
};
