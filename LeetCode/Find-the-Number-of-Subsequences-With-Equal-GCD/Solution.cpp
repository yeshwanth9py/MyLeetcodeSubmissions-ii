1class Solution {
2public:
3    int n;
4    vector<int> arr;
5    const int mod = 1e9+7;
6    int dp[201][201][201];
7    int rec(int ind, int g1, int g2){
8        if(ind == n){
9            return (g1>0 && (g1 == g2));
10        }
11        if(dp[ind][g1][g2] != -1) return dp[ind][g1][g2];
12        int w1 = rec(ind+1, g1, g2);
13        int w2 = rec(ind+1, __gcd(g1, arr[ind]), g2);
14        int w3 = rec(ind+1, g1, __gcd(arr[ind], g2));
15
16        return dp[ind][g1][g2] = (((w1+w2)%mod+w3)%mod + mod)%mod;;
17    }
18
19    int subsequencePairCount(vector<int>& nums) {
20        n = nums.size();
21        arr = nums;
22        memset(dp, -1, sizeof(dp));
23        return rec(0, 0, 0);
24    }
25};