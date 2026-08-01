1class Solution {
2public:
3    int mx;
4    int dt;
5    int dp[1<<21];
6    int rec(int mask, int cs){
7        if(cs>=dt){
8            return 0;  //current person lost, but prev person won
9        }
10        if(mask == (1<<mx)-1){ //cur person lost
11            return 0;
12        }
13        if(dp[mask] != -1) return dp[mask];
14        int ans = 0;
15        for(int i=0; i<mx; i++){
16            if((mask&(1<<i)) == 0){
17                int op = rec(mask|(1<<i), cs+(i+1));
18                if(op == 0){  //can force this move to make the other person lose
19                    return dp[mask] = 1;
20                }
21            }
22        }
23        return dp[mask] = 0;
24    }
25
26    bool canIWin(int maxch, int det) {
27        mx = maxch;
28        dt = det;
29        if(det == 0) return 1;
30        memset(dp, -1, sizeof(dp));
31        int posum = (mx*(mx+1))/2;
32        if(posum < det) return 0;
33        return rec(0, 0);
34    }
35};