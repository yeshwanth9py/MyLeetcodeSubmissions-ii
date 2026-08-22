1class Solution {
2public:
3    int minPathSum(vector<vector<int>>& arr) {
4        int n = arr.size();
5        int m = arr[0].size();
6        vector<vector<int>> dp(n+5, vector<int>(m+5, -1));
7
8        for(int i=n; i>=0; i--){
9            for(int j=m; j>=0; j--){
10                if(i == n || j == m){
11                    dp[i][j] = 1e9;
12                    continue;
13                }else if(i == n-1 && j == m-1){
14                    dp[i][j] = arr[i][j];
15                    continue;
16                }
17
18                int ri = dp[i+1][j];
19                int dow = dp[i][j+1];
20
21                dp[i][j] = arr[i][j] + min(ri, dow);
22            }
23        }
24
25        return dp[0][0];
26
27    }
28};