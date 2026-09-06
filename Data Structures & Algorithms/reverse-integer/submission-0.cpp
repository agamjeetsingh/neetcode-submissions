class Solution {
public:
    int reverse(int x) {
        long res = 0;
        bool neg = x < 0;
        x = abs(x);

        while (x > 0) {
            int n = x % 10;
            res = (res * 10) + n;
            x = x / 10;
        }

        res = res * (neg ? -1 : 1);

        return (INT_MIN <= res && res <= INT_MAX) ? res : 0;
    }
};
