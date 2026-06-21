1class Solution {
2public:
3    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
4        const int MOD = 1e9 + 7;
5        int n = value.size();
6
7        auto countGE = [&](long long x) {
8            long long cnt = 0;
9            for (int i = 0; i < n; i++) {
10                if (value[i] >= x) {
11                    cnt += (value[i] - x) / decay[i] + 1;
12                    if (cnt >= m) return cnt;
13                }
14            }
15            return cnt;
16        };
17
18        long long lo = 0, hi = *max_element(value.begin(), value.end());
19        long long cutoff = 0;
20
21        while (lo <= hi) {
22            long long mid = (lo + hi) / 2;
23
24            if (countGE(mid) >= m) {
25                cutoff = mid;
26                lo = mid + 1;
27            } else {
28                hi = mid - 1;
29            }
30        }
31
32        long long ans = 0;
33        long long taken = 0;
34
35        for (int i = 0; i < n; i++) {
36            if (value[i] > cutoff) {
37                long long k = (value[i] - (cutoff + 1)) / decay[i] + 1;
38                taken += k;
39
40                ans += 1LL * value[i] * k - 1LL * decay[i] * k * (k - 1) / 2;
41            }
42        }
43
44        ans += (m - taken) * cutoff;
45
46        return ans % MOD;
47    }
48};