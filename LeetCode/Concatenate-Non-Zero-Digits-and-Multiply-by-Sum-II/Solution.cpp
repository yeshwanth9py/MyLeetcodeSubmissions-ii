1class Solution {
2public:
3    const int mod = 1e9+7;
4    int binpow(int x, int n, int mod){
5        if(n == 0) return 1;
6        int ans = binpow(x, n/2, mod);
7        ans = ((1LL*ans*ans)%mod + mod)%mod;
8        if(n%2){
9            ans = ((1LL*ans*x)%mod + mod)%mod;
10        }
11        return ans;
12    }
13
14    vector<int> sumAndMultiply(string s, vector<vector<int>>& que) {
15        int n = s.size();
16        vector<int> pref(n, 0), len(n, 0), sufs(n, 0);
17
18        pref[0] = s[0]-'0';
19        len[0] = ((s[0] == '0')?0:1);
20        sufs[0] = (s[0]-'0');
21
22        for(int i=1; i<n; i++){
23            if(s[i] == '0'){
24                pref[i] = pref[i-1];
25                len[i] = len[i-1];
26                sufs[i] = sufs[i-1];
27            }else{
28                pref[i] = (1LL*pref[i-1]*10)%mod + (s[i]-'0');
29                len[i] = 1+len[i-1];
30                sufs[i] = sufs[i-1] + (s[i]-'0');
31            }
32        }
33
34        vector<int> asans;
35        for(auto q: que){
36            int l = q[0];
37            int r = q[1];
38
39            int curl = len[r] - (l-1>=0?len[l-1]:0);
40            int ans = (pref[r] - ((l-1>=0?pref[l-1]:0)*(1LL*binpow(10, curl, mod)))%mod + mod)%mod;
41
42            ans = ((1LL*ans*(sufs[r]-(l-1>=0?sufs[l-1]:0)+mod)%mod)%mod + mod)%mod;
43            asans.push_back(ans);
44        }
45
46        return asans;
47
48    }
49};