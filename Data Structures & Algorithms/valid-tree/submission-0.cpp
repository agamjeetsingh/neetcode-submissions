class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        return edges.size() == n - 1;
    }
};
