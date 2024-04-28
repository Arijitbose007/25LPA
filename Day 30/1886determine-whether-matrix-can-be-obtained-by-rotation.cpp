class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> validRotations(4, true);
        int n = mat.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] != target[i][j]) validRotations[0] = false;
                if(mat[i][j] != target[n-j-1][i]) validRotations[1] = false;
                if(mat[i][j] != target[n-i-1][n-j-1]) validRotations[2] = false;
                if(mat[i][j] != target[j][n-i-1]) validRotations[3] = false;
            }
        }
        return validRotations[0] || validRotations[1] || validRotations[2] || validRotations[3];
    }
};