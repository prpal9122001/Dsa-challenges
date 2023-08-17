//https://leetcode.com/problems/01-matrix/description/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Initialize the result matrix with maximum values
        vector<vector<int>> result(m, vector<int>(n, INT_MAX - 10000));
        
        // Traverse the matrix and update result for 0s
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                }
            }
        }
        
        // Traverse the matrix to update result for non-0s
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Check top and left neighbors for minimum distance
                if (i > 0) {
                    result[i][j] = min(result[i][j], result[i - 1][j] + 1);
                }
                if (j > 0) {
                    result[i][j] = min(result[i][j], result[i][j - 1] + 1);
                }
            }
        }
        
        // Traverse the matrix in reverse to update result for non-0s
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Check bottom and right neighbors for minimum distance
                if (i < m - 1) {
                    result[i][j] = min(result[i][j], result[i + 1][j] + 1);
                }
                if (j < n - 1) {
                    result[i][j] = min(result[i][j], result[i][j + 1] + 1);
                }
            }
        }
        
        return result;
    }
};
