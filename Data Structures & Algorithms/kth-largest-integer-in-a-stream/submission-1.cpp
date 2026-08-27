class KthLargest {
public:
    multiset<int> s;
    int cap = 0;

    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for (int num : nums) {
            s.insert(num);
            if (s.size() > cap) {
                s.erase(s.begin());
            }
        }
    }
    
    int add(int val) {
        s.insert(val);
        if (s.size() > cap) {
            s.erase(s.begin());
        }
        for (int num : s) {
            cout << num << endl;
        }
        return *s.begin();
    }
};
