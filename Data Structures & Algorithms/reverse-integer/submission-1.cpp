class Solution {
public:
    int reverse(int x) {
        long long res = 0;

        bool neg = x < 0;
        x = abs(x);

        while (x) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }

        res = res * (neg ? -1 : 1);

        return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};
