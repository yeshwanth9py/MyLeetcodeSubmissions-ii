1class Solution {
2public:
3    vector<int> arr;
4    int n;
5    vector<int> pref;
6    int dp[111][111];
7    int subsum(int ind){
8        if(ind>=n) return 0;
9        return pref[n-1] - (ind-1>=0?pref[ind-1]:0);
10    }
11
12    int rec(int ind, int m){
13        if(ind == n){
14            return 0;
15        }
16        if(dp[ind][m] != -1) return dp[ind][m];
17        int ans = 0;
18        for(int x=1; x<=2*m; x++){
19            if(ind+x>n) break;
20            ans = max(ans, subsum(ind)-rec(ind+x, max(m, x)));
21        }
22        return dp[ind][m] = ans;
23    }
24
25    int stoneGameII(vector<int>& piles) {
26        arr = piles;
27        n = arr.size();
28        pref.resize(n, 0);
29        pref[0] = arr[0];
30        memset(dp, -1, sizeof(dp));
31        for(int i=1; i<n; i++){
32            pref[i] = arr[i];
33            pref[i] += pref[i-1];
34        }
35
36        return rec(0, 1);
37    }
38};