class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> res(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!st.empty() && st.top().first < t) {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({t, i});
        }

        return res;
    }
};
