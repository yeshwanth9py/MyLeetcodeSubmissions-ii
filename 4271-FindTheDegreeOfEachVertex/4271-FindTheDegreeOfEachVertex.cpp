// Last updated: 6/17/2026, 2:15:55 PM
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1) cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};