class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> st; // {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int temp = temperatures[i];

            while (!st.empty() && st.top().first < temp) {
                auto [_, index] = st.top(); st.pop();
                res[index] = i - index;
            }

            st.push({temp, i});
        }

        return res;
    }
};
