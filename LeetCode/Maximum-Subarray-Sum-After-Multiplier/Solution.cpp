1class Solution {
2public:
3    long long n;
4    long long k;
5    vector<int> arr;
6    long long dp[100110][3][3];
7    long long rec(long long ind, long long state, long long typ){
8        if(ind == n){
9            return 0;
10        }
11        if(dp[ind][state][typ] != -1) return dp[ind][state][typ];
12        long long maxs = 0;
13        if(state == 0 || state == 2){
14            maxs = max(maxs, arr[ind] + rec(ind+1, state, typ));
15            if(state == 0) maxs = max(maxs, arr[ind]*k + rec(ind+1, 1, 1));
16            if(state == 0) maxs = max(maxs, arr[ind]/k + rec(ind+1, 1, 2));
17        }
18        if(state == 1){
19            if(typ==1){
20                maxs = max(maxs, arr[ind]*k + rec(ind+1, 1, 1));
21            }else{
22                maxs = max(maxs, arr[ind]/k + rec(ind+1, 1, 2));
23            }
24            maxs = max(maxs, arr[ind] + rec(ind+1, 2, 0));
25        }
26
27        return dp[ind][state][typ] = maxs;
28    }
29
30    long long maxSubarraySum(vector<int>& nums, long long kk) {
31        long long maxs = -1e18;
32        arr = nums;
33        k = kk;
34        n = nums.size();
35        memset(dp, -1, sizeof(dp));
36        long long mx = *(max_element(nums.begin(), nums.end()));
37        if(mx<=0){
38            return mx/k;
39        }
40        for(long long i=0; i<n; i++){
41            maxs = max(maxs, rec(i, 0, 0));
42        }
43
44        return maxs;
45    }
46};