class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int top = pq.top(); pq.pop();
            int secondTop = pq.top(); pq.pop();

            if (top != secondTop) pq.push(top - secondTop);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
