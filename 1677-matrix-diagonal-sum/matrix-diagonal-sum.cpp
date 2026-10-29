class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, m = mat.size(), n = mat[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j || m - 1 == i + j) {
                    sum += mat[i][j];
                }
            }
        }

        return sum;
    }
};