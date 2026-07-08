1class Solution {
2public:
3    const long long mod = 1e9+7;
4    long long n, m;
5    vector<string> arr;
6    vector<vector<long long>> cnt;
7    long long dp[111][111];
8
9    long long rec(long long r, long long c){
10        if(r<0 || c<0 || r>=n || c>=m || arr[r][c] == 'X') return -1e9;
11        if(r == 0 && c == 0){
12            cnt[r][c] = 1;
13            return 0;
14        }
15
16        if(dp[r][c] != -1) return dp[r][c];
17
18        long long down = rec(r-1, c);
19        long long right = rec(r, c-1);
20        long long diag = rec(r-1, c-1);
21
22        long long mxv = max({down, right, diag});
23        if(mxv<0){
24            cnt[r][c] = 0;
25            return dp[r][c] = mxv;
26        }
27        cnt[r][c] = 0;
28        if(mxv == down && r-1>=0){
29            cnt[r][c] += cnt[r-1][c];
30            cnt[r][c] = (cnt[r][c]%mod + mod)%mod;
31        }
32        if(mxv == right && c-1>=0){
33            cnt[r][c] += cnt[r][c-1];
34            cnt[r][c] = (cnt[r][c]%mod + mod)%mod;
35        }
36        if(mxv == diag && r-1>=0 && c-1>=0){
37            cnt[r][c] += (cnt[r-1][c-1]);
38            cnt[r][c] = (cnt[r][c]%mod + mod)%mod;
39        }
40
41        return dp[r][c] = ((mxv + arr[r][c]-'0')%mod + mod)%mod;
42    }
43
44    vector<int> pathsWithMaxScore(vector<string>& arr) {
45        n = arr.size();
46        m = arr[0].size();
47        arr[n-1][m-1] = '0';
48        arr[0][0] = '0';
49        cnt.assign(n, vector<long long>(m, 0));
50
51        this->arr = arr;
52        memset(dp, -1, sizeof(dp));
53        int ans = rec(n-1, m-1);
54        if(ans<0) return {0, 0};
55        return {ans, (int) cnt[n-1][m-1]};
56    }
57};