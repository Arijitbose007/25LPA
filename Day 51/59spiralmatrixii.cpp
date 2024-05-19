class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            ans.push_back(vector<int>(n));
        }
        int itr = 1;
        for(int st = 0; st < (n+1)/2; st++) {
            int i, j;
            // increasing column
            for(i=st,j=st; j<n-st; j++) {
                ans[i][j] = itr++;
            }
            //increasing row
            for(i=st+1,j=n-st-1; i<n-st; i++) {
                ans[i][j] = itr++;
            }
            //decreasing column
            for(i=n-st-1,j=n-st-2; j>=st; j--) {
                ans[i][j] = itr++;
            }
            //decreasing row
            for(i=n-st-2,j=st; i>st; i--) {
                ans[i][j] = itr++;
            }
        }
        return ans;
    }
};