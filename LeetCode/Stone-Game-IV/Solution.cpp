1vector<int> allsq;
2static int noti = 0;
3
4void pre(){
5    for(int i=1; i*i<=1e5; i++){
6        allsq.push_back(i*i);
7    }
8}
9
10class Solution {
11public:
12    Solution(){
13        if(noti == 0){
14            pre();
15            noti = 1;
16        }
17    }
18    int dp[100010];
19    bool rec(int ind){
20        if(ind == 0){
21            return 0;
22        }
23        if(dp[ind] != -1) return dp[ind];
24        int ans = 0;
25        for(int i=0; i<allsq.size(); i++){
26            if(ind-allsq[i]<0) break;
27            if(rec(ind - allsq[i]) == 0){
28                return dp[ind] = 1;
29            }
30        }
31
32        return dp[ind] = 0;
33    }
34
35    bool winnerSquareGame(int n) {
36        // cout<<allsq[0]<<" ";
37        memset(dp, -1, sizeof(dp));
38        return rec(n);
39    }
40};