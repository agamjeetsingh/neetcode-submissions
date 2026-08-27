class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        queue<char> blockList;
        vector<int> lastRan(26);
        vector<int> freqs(26);

        auto comp = [](pair<int, char> p1, pair<int, char> p2) {
            return p1.first < p2.first;
        };

        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comp)> pq(comp); // ready list

        for (char c : tasks) freqs[c - 'A']++;

        for (int i = 0; i < 26; i++) {
            if (freqs[i] > 0) pq.push({freqs[i], i + 'A'});
        }

        while (!pq.empty() || !blockList.empty()) {
            if (!pq.empty()) {
                auto [freq, c] = pq.top(); pq.pop();
                // cout << c << endl;
                if (--freq > 0) freqs[c - 'A'] = freq;
                if (freq > 0) {
                    blockList.push(c);
                    lastRan[c - 'A'] = res;
                }
            }

            if (pq.empty() && !blockList.empty()) {
                int target = lastRan[blockList.front() - 'A'] + n;
                if (target > res) res = target;
            }

            while (!blockList.empty() && res - lastRan[blockList.front() - 'A'] >= n) {
                pq.push({freqs[blockList.front() - 'A'], blockList.front()});
                blockList.pop();
            }
            
            res++;
        }

        return res;
    }
};
