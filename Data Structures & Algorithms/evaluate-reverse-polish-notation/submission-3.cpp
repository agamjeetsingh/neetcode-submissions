class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& tok: tokens) {
            if (tok == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 + top1);
            } else if (tok == "-") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 - top1);
            } else if (tok == "/") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 / top1);
            } else if (tok == "*") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 * top1);
            } else {
                st.push(stoi(tok));
            }
        }

        return st.top();
    }
};
