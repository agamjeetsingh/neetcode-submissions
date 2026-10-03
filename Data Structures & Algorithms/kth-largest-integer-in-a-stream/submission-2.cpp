class KthLargest {
public:
    multiset<int> s;
    int k;

    KthLargest(int k, vector<int>& nums) {
        for (int num: nums) {
            s.insert(num);
            if (s.size() > k) s.erase(s.begin());
        }
        this->k = k;
    }
    
    int add(int val) {
        s.insert(val);
        if (s.size() > k) s.erase(s.begin());

        return *s.begin();
    }
};
