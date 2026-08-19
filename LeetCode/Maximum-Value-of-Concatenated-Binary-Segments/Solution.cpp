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
28            // if(a.second == 0 || b.second == 0){
29            //     return a.second<b.second;
30            // }
31            // if(a.first>0 && a.second>0 && b.first>0 && b.second>0){
32            //     return a.second<b.second;
33            // }
34            // return a.first>b.first;
35
36                // Case 1:
37                // Segments having only 1s come first.
38                if (a.second == 0 && b.second != 0)
39                    return true;
40
41                if (a.second != 0 && b.second == 0)
42                    return false;
43
44                // Both are only 1s.
45                if (a.second == 0 && b.second == 0)
46                    return a.first > b.first;
47
48                // Case 2:
49                // Segments having only 0s go last.
50                if (a.first == 0 && b.first != 0)
51                    return false;
52
53                if (a.first != 0 && b.first == 0)
54                    return true;
55
56                // Both have at least one 1 and one 0.
57                // More 1s first.
58                if (a.first != b.first)
59                    return a.first > b.first;
60
61                // Same number of 1s -> fewer 0s first.
62                return a.second < b.second;
63        });
64
65        long long ans = 0;
66
67        for(long long i=0; i<n; i++){
68            auto [no1, no0] = vec[i];
69            // long long curv = (1<<ans-1) + (1<<ans-2) + (1<<ans-3)
70            long long curv = ((binpow(2, tot)) - (binpow(2, tot-no1)) + mod)%mod;
71            tot -= (no1+no0);
72            ans += curv;
73            ans = (ans%mod + mod)%mod;
74        }
75
76        return ans;
77
78    }
79};