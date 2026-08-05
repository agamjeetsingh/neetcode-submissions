class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& s : tokens) {
            int num = 0;
            auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), num);

            if (ec == errc()) {
                st.push(num);

            } else if (s == "+") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();

                st.push(num1 + num2);

            } else if (s == "-") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();

                st.push(num2 - num1);
            } else if (s == "*") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();

                st.push(num1 * num2);
            } else if (s == "/") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();

                st.push(num2 / num1);
            }
        }

        return st.top();
    }
};
