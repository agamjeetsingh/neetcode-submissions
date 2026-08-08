class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 2;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        int n = beginWord.size();
        wordList.push_back(beginWord);
        wordList.push_back(endWord);

        int res = 0;

        unordered_map<string, vector<string>> adjList;
        unordered_set<string> visited;
        queue<string> q;

        for (string& word1: wordList) {
            for (string& word2: wordList) {
                if (isAdj(word1, word2)) {
                    adjList[word1].push_back(word2);
                    adjList[word2].push_back(word1);
                }
            }
        }

        q.push(beginWord);
        visited.insert(beginWord);

        while (!q.empty()) {
            res++;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string front = q.front(); q.pop();
                // cout << front << endl;

                for (string& neighbour: adjList[front]) {
                    if (visited.contains(neighbour)) continue;
                    if (neighbour == endWord) return res + 1;
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }

        return 0;
    }

    bool isAdj(string& word1, string& word2) {
        int misMatch = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i]) {
                misMatch++;
                if (misMatch > 1) {
                    return false;
                }
            }
        }
        return misMatch == 1;
    }
};
