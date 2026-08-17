1class Solution {
2public:
3    long long m;
4    vector<int> arr;
5    long long dp[1501][1501][2];
6    long long rec(long long l, long long r, long long loc){
7        if(l == 0 && r == m-1) return 0;
8        if(dp[l][r][loc] != -1) return dp[l][r][loc];
9        long long rem = m-(r-l+1);
10        long long ans = 1e18;
11        if(loc == 0){
12            if(l-1>=0){
13                long long curt = (arr[l]-arr[l-1])*rem + rec(l-1, r, 0);
14                ans = min(ans, curt);
15            }
16
17            if(r+1<m){
18                long long curt = (arr[r+1]-arr[l])*rem + rec(l, r+1, 1);
19                ans = min(ans, curt);
20            }
21        }else{
22            if(l-1>=0){
23                long long curt = (arr[r]-arr[l-1])*rem + rec(l-1, r, 0);
24                ans = min(ans, curt);
25            }
26
27            if(r+1<m){
28                long long curt = (arr[r+1]-arr[r])*rem + rec(l, r+1, 1);
29                ans = min(ans, curt);
30            }
31        }
32        return dp[l][r][loc] = ans;
33    }
34
35    long long elevatorRequests(long long n, long long s, vector<int>& arr) {
36        if(find(arr.begin(), arr.end(), s) == arr.end()){
37            arr.push_back(s);
38        }
39        sort(arr.begin(), arr.end());
40        this->m = arr.size();
41        this->arr = arr;
42
43        memset(dp, -1, sizeof(dp));
44
45        long long ind = lower_bound(arr.begin(), arr.end(), s)-arr.begin();
46
47        return rec(ind, ind, 0);
48    }
49};