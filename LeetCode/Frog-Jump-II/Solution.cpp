1#include <vector>
2#include <algorithm>
3
4class Solution {
5public:
6    int maxJump(std::vector<int>& arr) {
7        int n = arr.size();
8        int lo = 1;
9        int hi = arr.back() - arr[0];
10        int ans = hi;
11
12        // O(N) Greedy check function
13        auto check = [&](int md) {
14            std::vector<bool> visited(n, false);
15
16            // 1. Forward Journey: Jump to farthest reachable stone within 'md'
17            int cur = 0;
18            while (cur < n - 1) {
19                int nxt = cur;
20                while (nxt + 1 < n && arr[nxt + 1] - arr[cur] <= md) {
21                    nxt++;
22                }
23                
24                // If stuck, this jump distance (md) is too small
25                if (nxt == cur) return false; 
26
27                cur = nxt;
28                if (cur < n - 1) {
29                    visited[cur] = true; // Mark stone as used
30                }
31            }
32
33            // 2. Backward Journey: Visit all remaining unvisited stones
34            cur = n - 1;
35            for (int i = n - 2; i >= 0; i--) {
36                if (!visited[i]) {
37                    if (arr[cur] - arr[i] > md) return false;
38                    cur = i;
39                }
40            }
41
42            return true;
43        };
44
45        // Binary Search on Answer
46        while (lo <= hi) {
47            int mid = lo + (hi - lo) / 2;
48            if (check(mid)) {
49                ans = mid;
50                hi = mid - 1; // Search for a smaller valid max jump
51            } else {
52                lo = mid + 1; // Increase max jump length
53            }
54        }
55
56        return ans;
57    }
58};