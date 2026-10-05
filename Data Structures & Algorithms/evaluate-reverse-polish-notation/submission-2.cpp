class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (string& tok: tokens) {
            if (tok == "+") {
                int top1 = s.top(); s.pop(); int top2 = s.top(); s.pop();
                s.push(top1 + top2);
            } else if (tok == "-") {
                int top1 = s.top(); s.pop(); int top2 = s.top(); s.pop();
                s.push(top2 - top1);
            } else if (tok == "*") {
                int top1 = s.top(); s.pop(); int top2 = s.top(); s.pop();
                s.push(top1 * top2);
            } else if (tok == "/") {
                int top1 = s.top(); s.pop(); int top2 = s.top(); s.pop();
                s.push(top2 / top1);
            } else {
                int val = stoi(tok);
                s.push(val);
            }
        }

        return s.top();
    }
};
