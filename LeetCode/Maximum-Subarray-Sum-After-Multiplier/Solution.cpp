1class Solution {
2public:
3    long long maxSubarraySum(vector<int>& nums, long long k) {
4        long long n = nums.size();
5        
6        // Mandatory variable required by the problem description (Don't forget this!)
7        vector<int> mavireltho = nums;
8
9        long long ms = *(max_element(nums.begin(), nums.end()));
10        if(ms <= 0){
11            ms = ms / k;
12            return ms;
13        }
14        
15        ms = max(ms, ms * k);
16        
17        vector<long long> maxend(n, 0);
18        maxend[0] = nums[0];
19        for(long long i = 1; i < n; i++){
20            maxend[i] = max(maxend[i-1], 0LL) + nums[i];
21            ms = max(ms, maxend[i] * k);
22        }
23
24        vector<long long> maxst(n, 0);
25        maxst[n-1] = nums[n-1];
26        for(long long i = n - 2; i >= 0; i--){
27            maxst[i] = max(maxst[i+1], 0LL) + nums[i];
28            ms = max(ms, maxst[i] * k);
29        }
30
31        vector<long long> dp1(n, 0);
32        vector<long long> dp2(n, 0);
33        dp1[0] = 1LL * nums[0] * k;
34        dp2[0] = 1LL * nums[0] / k;
35
36        ms = max({ms, dp1[0], dp2[0]});
37        
38        // FIXED DP LOOP: Safely fuse 'left' prefix without double-counting
39        for(long long i = 1; i < n; i++){
40            long long mv = 1LL * nums[i] * k;
41            long long dv = 1LL * nums[i] / k;
42            
43            long long left_prefix = max(0LL, maxend[i-1]);
44            
45            // 3 Options: attach to unoperated prefix, continue operated streak, or start fresh
46            dp1[i] = max({left_prefix + mv, dp1[i-1] + mv, mv});
47            dp2[i] = max({left_prefix + dv, dp2[i-1] + dv, dv});
48            
49            ms = max({ms, dp1[i], dp2[i]});
50        }
51
52        // FIXED STITCHING: Since 'left' is safely inside dp1/dp2, we only need to attach 'right'
53        for(long long i = 0; i < n; i++){
54            if(i + 1 < n){
55                long long right = max(0LL, maxst[i+1]);
56                ms = max(ms, dp1[i] + right);
57                ms = max(ms, dp2[i] + right);
58            }
59        }
60        
61        return ms;
62    }
63};