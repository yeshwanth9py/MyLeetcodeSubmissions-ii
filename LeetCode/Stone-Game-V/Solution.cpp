1class Solution {
2public:
3    vector<int> pref;
4    int dp[501][501];
5    int rec(int l, int r){
6        if(l>r) return 0;
7        if(l == r) return 0;
8        if(dp[l][r] != -1) return dp[l][r];
9        int ans = 0;
10        for(int i=l; i<=r; i++){
11            int s1 = pref[i] - (l-1>=0?pref[l-1]:0);
12            int s2 = pref[r] - pref[i];
13            if(s1 == s2){
14                ans = max(ans, max(s2+rec(i+1, r), s1+rec(l, i)));
15            }else if(s1>s2){
16                ans = max(ans, s2+rec(i+1, r));
17            }else{
18                ans = max(ans, s1+rec(l, i));
19            }
20        }
21        return dp[l][r] = ans;
22    }
23
24    int stoneGameV(vector<int>& arr) {
25        int n = arr.size();
26        pref.resize(n, 0);
27        memset(dp, -1, sizeof(dp));
28        pref[0] = arr[0];
29        for(int i=1; i<n; i++){
30            pref[i] = pref[i-1] + arr[i];
31        }
32
33        return rec(0, n-1);
34    }
35};