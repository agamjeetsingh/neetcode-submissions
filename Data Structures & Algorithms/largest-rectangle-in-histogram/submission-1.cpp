class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> right = biggestRight(heights);
        vector<int> left = biggestLeft(heights);

        for (int i = 0; i < heights.size(); i++) {
            int length = 1 + left[i] + right[i];
            res = max(res, length * heights[i]);
        }

        return res;
    }

    vector<int> biggestRight(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> st;

        for (int i = 0; i < temperatures.size(); i++) {
            int temp = temperatures[i];
            while (!st.empty()) {
                if (st.top().first > temp) {
                    res[st.top().second] = i - st.top().second - 1;
                    st.pop();
                } else {
                    break;
                }
            }
            st.push({temp, i});
        }

        while (!st.empty()) {
            res[st.top().second] = temperatures.size() - st.top().second - 1;
            st.pop();
        }

        return res;
    }

    vector<int> biggestLeft(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> st;

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int temp = temperatures[i];
            while (!st.empty()) {
                if (st.top().first > temp) {
                    res[st.top().second] = st.top().second - i - 1;
                    st.pop();
                } else {
                    break;
                }
            }
            st.push({temp, i});
        }

        while (!st.empty()) {
            res[st.top().second] = st.top().second;
            st.pop();
        }

        return res;
    }
};