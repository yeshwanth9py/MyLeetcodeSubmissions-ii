1class Solution {
2public:
3    vector<int> arr;
4    int dp[301][5001];
5    int rec(int ind, int rem){
6        if(rem<0) return 0;
7        if(ind == arr.size()){
8            return rem == 0;
9        }
10        if(dp[ind][rem] != -1) return dp[ind][rem];
11        int dontake = rec(ind+1, rem);
12        int take = rec(ind, rem-arr[ind]);
13        return dp[ind][rem] = dontake + take;
14    }
15    int change(int amt, vector<int>& coins) {
16        arr = coins;
17        memset(dp, - 1, sizeof(dp));
18        return rec(0, amt);
19    }
20};