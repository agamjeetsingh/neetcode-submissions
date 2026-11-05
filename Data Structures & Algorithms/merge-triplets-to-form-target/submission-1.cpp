class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x_valid = false;
        bool y_valid = false;
        bool z_valid = false;

        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] == target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) x_valid = true;
            if (triplets[i][1] == target[1] && triplets[i][0] <= target[0] && triplets[i][2] <= target[2]) y_valid = true;
            if (triplets[i][2] == target[2] && triplets[i][1] <= target[1] && triplets[i][0] <= target[0]) z_valid = true;
        }

        return x_valid && y_valid && z_valid;
    }
};
