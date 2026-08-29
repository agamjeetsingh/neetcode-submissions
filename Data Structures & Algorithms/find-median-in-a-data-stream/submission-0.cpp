class MedianFinder {
public:
    multiset<int, greater<int>> left;
    multiset<int> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty()) {
            left.insert(num);
        } else {
            if (*left.begin() >= num) {
                left.insert(num);
            } else {
                right.insert(num);
            }
        }

        if (left.size() - right.size() == 2) {
            int biggest = *left.begin();
            left.erase(left.begin());
            right.insert(biggest);
        } else if (right.size() - left.size() == 1) {
            int smallest = *right.begin();
            right.erase(right.begin());
            left.insert(smallest);
        }
    }
    
    double findMedian() {
        if (left.size() == right.size()) {
            return (*left.begin() + *right.begin()) / 2.0;
        } else {
            return *left.begin();
        }
    }
};
