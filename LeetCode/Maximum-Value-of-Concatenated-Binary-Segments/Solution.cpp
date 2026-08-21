1class Solution {
2public:
3    const long long mod = 1e9+7;
4
5    long long binpow(long long x, long long n){
6        if(n == 0) return 1;
7        long long ans = binpow(x, n/2);
8        ans = ((ans*ans)%mod + mod)%mod;
9
10        if(n&1){
11            ans = ((ans*x)%mod + mod)%mod;
12        }
13
14        return ans;
15    }
16
17    long long maxValue(vector<int>& nums1, vector<int>& nums0) {
18        vector<pair<long long, long long>> vec;
19        long long n = nums1.size();
20
21        long long tot = 0;
22        for(long long i=0; i<n; i++){
23            vec.push_back({nums1[i], nums0[i]});
24            tot += nums1[i] + nums0[i];
25        }
26
27        sort(vec.begin(), vec.end(), [&](pair<long long, long long> &a, pair<long long, long long> &b){
28            if(a.second == 0 || b.second == 0){
29                return a.second<b.second;
30            }
31
32            if(a.first == 0 || b.first == 0){
33                return a.first>b.first;
34            }
35
36            if(a.first == b.first){
37                return a.second<b.second;
38            }
39
40            return a.first>b.first;
41        });
42
43        long long ans = 0;
44
45        for(long long i=0; i<n; i++){
46            auto [no1, no0] = vec[i];
47            // long long curv = (1<<ans-1) + (1<<ans-2) + (1<<ans-3)
48            long long curv = ((binpow(2, tot)) - (binpow(2, tot-no1)) + mod)%mod;
49            tot -= (no1+no0);
50            ans += curv;
51            ans = (ans%mod + mod)%mod;
52        }
53
54        return ans;
55
56    }
57};
58
59
60
61
62