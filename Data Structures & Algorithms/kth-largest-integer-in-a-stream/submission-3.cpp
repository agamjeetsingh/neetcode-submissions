class KthLargest {
public:
    multiset<int> ms;
    int capacity;

    KthLargest(int k, vector<int>& nums): capacity(k) {
        for (int num: nums) {
            ms.insert(num);
            if (ms.size() > capacity) {
                ms.erase(ms.begin());
            }
        }
    }
    
    int add(int val) {
        ms.insert(val);
        int res;
        if (ms.size() > capacity) {
            ms.erase(ms.begin());
        }

        return *ms.begin();
    }
};
