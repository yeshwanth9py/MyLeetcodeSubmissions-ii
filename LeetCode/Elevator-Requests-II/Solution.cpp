1class Solution {
2public:
3
4    vector<int> a;
5    int m;
6
7    // dp[l][r][side]
8    //
9    // side = 0 -> currently at a[l]
10    // side = 1 -> currently at a[r]
11    vector<vector<array<long long, 2>>> dp;
12
13    long long solve(int l, int r, int side) {
14
15        // Everything is fulfilled.
16        if (l == 0 && r == m - 1) {
17            return 0;
18        }
19
20        // If we already calculated this state,
21        // simply return the stored answer.
22        if (dp[l][r][side] != -1) {
23            return dp[l][r][side];
24        }
25
26        /*
27            Number of requests still waiting.
28
29            Interval [l ... r] contains:
30
31                r-l+1 elements
32
33            One of those is 'start', which was not an actual
34            unfulfilled request.
35
36            Therefore fulfilled requests = r-l
37
38            Total actual requests = m-1
39
40            remaining = (m-1) - (r-l)
41        */
42        long long remaining = (m - 1) - (r - l);
43
44        long long ans = LLONG_MAX;
45
46        // =====================================================
47        // Elevator currently at LEFT endpoint a[l]
48        // =====================================================
49        if (side == 0) {
50
51            // ---------------------------------------------
52            // Choice 1: Expand interval to the LEFT
53            // ---------------------------------------------
54            if (l > 0) {
55
56                long long distance = a[l] - a[l - 1];
57
58                /*
59                    We move 'distance' floors.
60
61                    During this whole movement,
62                    'remaining' requests are still waiting.
63
64                    So additional penalty is:
65
66                        distance * remaining
67                */
68                long long cost =
69                    distance * remaining;
70
71                ans = min(
72                    ans,
73                    cost + solve(l - 1, r, 0)
74                );
75            }
76
77            // ---------------------------------------------
78            // Choice 2: Expand interval to the RIGHT
79            // ---------------------------------------------
80            if (r + 1 < m) {
81
82                long long distance = a[r + 1] - a[l];
83
84                long long cost =
85                    distance * remaining;
86
87                ans = min(
88                    ans,
89                    cost + solve(l, r + 1, 1)
90                );
91            }
92        }
93
94        // =====================================================
95        // Elevator currently at RIGHT endpoint a[r]
96        // =====================================================
97        else {
98
99            // ---------------------------------------------
100            // Choice 1: Expand interval to the LEFT
101            // ---------------------------------------------
102            if (l > 0) {
103
104                long long distance = a[r] - a[l - 1];
105
106                long long cost =
107                    distance * remaining;
108
109                ans = min(
110                    ans,
111                    cost + solve(l - 1, r, 0)
112                );
113            }
114
115            // ---------------------------------------------
116            // Choice 2: Expand interval to the RIGHT
117            // ---------------------------------------------
118            if (r + 1 < m) {
119
120                long long distance = a[r + 1] - a[r];
121
122                long long cost =
123                    distance * remaining;
124
125                ans = min(
126                    ans,
127                    cost + solve(l, r + 1, 1)
128                );
129            }
130        }
131
132        // Store result before returning.
133        return dp[l][r][side] = ans;
134    }
135
136
137    long long elevatorRequests(int n, int start, vector<int>& requests) {
138
139        a.clear();
140
141        /*
142            If start itself is requested, that request is fulfilled
143            immediately at time 0, so it contributes 0.
144
145            We don't need to keep it as an actual request.
146        */
147        for (int x : requests) {
148            if (x != start) {
149                a.push_back(x);
150            }
151        }
152
153        sort(a.begin(), a.end());
154
155        /*
156            Insert start into the sorted array.
157
158            Example:
159
160                requests = [0, 2, 9]
161                start = 5
162
163                after inserting:
164
165                [0, 2, 5, 9]
166                      ^
167                    start
168        */
169        int pos =
170            lower_bound(a.begin(), a.end(), start) - a.begin();
171
172        a.insert(a.begin() + pos, start);
173
174        m = a.size();
175
176        /*
177            Initially:
178
179                l = pos
180                r = pos
181
182            Only 'start' is already fulfilled.
183
184            Elevator is at a[pos], so side = 0.
185        */
186
187        dp.assign(
188            m,
189            vector<array<long long, 2>>(
190                m,
191                { -1, -1 }
192            )
193        );
194
195        return solve(pos, pos, 0);
196    }
197};