class KthLargest {
public:
    multiset<int> s;
    int cap;

    KthLargest(int k, vector<int>& nums) {
        cap = k;

        for (int num: nums) add(num);
    }
    
    int add(int val) {
        s.insert(val);

        if (s.size() > cap) {
            s.erase(s.begin());
        }

        return *s.begin();
    }
};
