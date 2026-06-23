1class Solution {
2public:
3    long long n, l, r;
4    const long long mod = 1e9+7;
5    long long dp[2001][2001][2];
6    long long rec(){
7        // if(prev<l || prev>r) return 0;
8        // if(ind == n){   
9        //     return 1;
10        // }
11
12        // if(dp[ind][prev][inc] != -1) return dp[ind][prev][inc];
13        // if(inc){
14        //     return dp[ind][prev][inc] = ((rec(ind+1, prev+1, 0) + rec(ind, prev+1, 1))%mod + mod)%mod;
15        // }else{
16        //     return dp[ind][prev][inc] = ((rec(ind+1, prev-1, 1) + rec(ind, prev-1, 0))%mod + mod)%mod;
17        // }
18
19        for(int ind=n; ind>=0; ind--){
20            for(int prev=r; prev>=l; prev--){
21                if(ind==n){
22                    dp[ind][prev][0] = dp[ind][prev][1] = 1;
23                    continue;
24                }
25                dp[ind][prev][1] = ((prev+1<=r?dp[ind+1][prev+1][0]:0)%mod + (prev+1<=r?dp[ind][prev+1][1]:0)%mod)%mod;
26            }
27            for(int prev=l; prev<=r; prev++){
28                if(ind==n){
29                    dp[ind][prev][0] = dp[ind][prev][1] = 1;
30                    continue;
31                }
32                dp[ind][prev][0] = ((prev-1>=l?dp[ind+1][prev-1][1]:0)%mod + (prev-1>=l?dp[ind][prev-1][0]:0)%mod)%mod;
33            }
34        }
35        
36        return ((dp[0][l][1] + dp[0][r][0])%mod+mod)%mod;
37    }
38
39    long long zigZagArrays(long long nn, long long ll, long long rr) {
40        n = nn;
41        l = ll;
42        r = rr;
43
44        long long ans = 0;
45        ans = rec();
46        return ans;
47    }
48};