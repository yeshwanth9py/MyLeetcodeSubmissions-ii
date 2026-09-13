1class Solution {
2public:
3    struct Node {
4        long long wt;
5        array<int, 4> id;
6        int sz;
7
8        Node() {
9            wt = 0;
10            sz = 0;
11            id.fill(INT_MAX);
12        }
13    };
14
15    vector<vector<int>> arr;
16    vector<int> nxt;
17    Node dp[50001][5];
18    bool vis[50001][5];
19
20    // Compare index lists lexicographically
21    bool smaller(const Node& a, const Node& b) {
22        int sz = min(a.sz, b.sz);
23
24        for (int i = 0; i < sz; i++) {
25            if (a.id[i] != b.id[i])
26                return a.id[i] < b.id[i];
27        }
28
29        return a.sz < b.sz;
30    }
31
32    // Add current index to a solution
33    Node add(Node x, int idx, long long weight) {
34        x.wt += weight;
35
36        int pos = x.sz;
37        while (pos > 0 && x.id[pos - 1] > idx) {
38            x.id[pos] = x.id[pos - 1];
39            pos--;
40        }
41
42        x.id[pos] = idx;
43        x.sz++;
44
45        return x;
46    }
47
48    Node rec(int ind, int cnt) {
49        if (cnt == 4 || ind == arr.size())
50            return Node();
51
52        if (vis[ind][cnt])
53            return dp[ind][cnt];
54
55        vis[ind][cnt] = true;
56
57        // TAKE
58        Node take = rec(nxt[ind], cnt + 1);
59        take = add(take, arr[ind][3], arr[ind][2]);
60
61        // NOT TAKE
62        Node skip = rec(ind + 1, cnt);
63
64        if (take.wt > skip.wt)
65            return dp[ind][cnt] = take;
66
67        if (skip.wt > take.wt)
68            return dp[ind][cnt] = skip;
69
70        // Same weight -> lexicographically smaller indices
71        if (smaller(take, skip))
72            return dp[ind][cnt] = take;
73
74        return dp[ind][cnt] = skip;
75    }
76
77    vector<int> maximumWeight(vector<vector<int>>& intervals) {
78        arr = intervals;
79
80        int n = arr.size();
81
82        // Add original index
83        for (int i = 0; i < n; i++)
84            arr[i].push_back(i);
85
86        // Sort by start, then end, then weight, then original index
87        sort(arr.begin(), arr.end());
88
89        // Precompute next interval
90        nxt.resize(n);
91
92        for (int i = 0; i < n; i++) {
93            int target = arr[i][1] + 1;
94
95            nxt[i] = lower_bound(
96                arr.begin(),
97                arr.end(),
98                vector<int>{target, -1, -1, -1}
99            ) - arr.begin();
100        }
101
102        memset(vis, false, sizeof(vis));
103
104        Node res = rec(0, 0);
105
106        vector<int> ans;
107
108        for (int i = 0; i < res.sz; i++)
109            ans.push_back(res.id[i]);
110
111        sort(ans.begin(), ans.end());
112
113        return ans;
114    }
115};