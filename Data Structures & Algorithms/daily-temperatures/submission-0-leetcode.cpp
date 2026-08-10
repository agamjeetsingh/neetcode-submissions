class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> st;

        for (int i = 0; i < temperatures.size(); i++) {
            int temp = temperatures[i];
            while (!st.empty()) {
                if (st.top().first < temp) {
                    res[st.top().second] = i - st.top().second;
                    st.pop();
                } else {
                    break;
                }
            }
            st.push({temp, i});
        }

        return res;
    }
};
