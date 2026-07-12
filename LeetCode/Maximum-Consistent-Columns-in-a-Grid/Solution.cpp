1class Solution {
2public:
3    vector<vector<int>> arr;
4    int n, m;
5    int limit;
6    int dp[251][255];
7    int rec(int ind, int pind){
8        if(ind == m){
9            return 0;
10        }
11        if(dp[ind][pind+1] != -1) return dp[ind][pind+1];
12        int ans = rec(ind+1, pind);
13
14        bool iscomp = 1;
15        if(pind == -1){
16            ans = max(ans, 1+rec(ind+1, ind));
17            return dp[ind][pind+1] = ans;
18        }
19        for(int i=0; i<n; i++){
20            if(abs(arr[i][ind]-arr[i][pind])>limit){
21                iscomp = 0;
22            }
23        }
24
25        if(iscomp){
26            ans = max(ans, 1+rec(ind+1, ind));
27        }
28
29        return dp[ind][pind+1] = ans;
30    }
31
32
33    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
34        arr = grid;
35        n = arr.size();
36        m = arr[0].size();
37        memset(dp, -1, sizeof(dp));
38        this->limit = limit;
39
40        return rec(0, -1);
41    }
42};