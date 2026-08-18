1class Solution {
2public:
3
4    long long m;
5
6    /*
7        dp[ind][mask] =
8        minimum time needed to reach state (ind, mask).
9
10        It means:
11
12        "What is the earliest time at which the elevator
13         can be at arr[ind][1] with all requests in mask
14         already fulfilled?"
15    */
16    long long dp[17][1 << 16];
17
18    // arr[i] = {arrival time, requested floor}
19    vector<vector<int>> arr;
20
21
22    void rec(long long ind, long long mask, long long time) {
23
24        /*
25            If this state has already been reached earlier
26            at an equal or smaller time, then this path can
27            never produce a better answer.
28
29            So stop exploring it.
30        */
31        if(dp[ind][mask] <= time) {
32            return;
33        }
34
35        /*
36            We have found the earliest time for this state
37            so far.
38        */
39        dp[ind][mask] = time;
40
41
42        // All requests are completed.
43        if(mask == (1LL << m) - 1) {
44            return;
45        }
46
47
48        // Try every request as the next request.
49        for(long long i = 0; i < m; i++) {
50
51            // Already completed.
52            if(mask & (1LL << i)) {
53                continue;
54            }
55
56
57            // Current elevator floor.
58            long long currentFloor = arr[ind][1];
59
60            // Next request's floor.
61            long long nextFloor = arr[i][1];
62
63
64            /*
65                Elevator can move both up and down.
66
67                Each floor takes 1 second.
68
69                Therefore movement takes:
70                    |currentFloor - nextFloor|
71            */
72            long long move =
73                abs(nextFloor - currentFloor);
74
75
76            /*
77                Time when we reach nextFloor.
78            */
79            long long reachTime =
80                time + move;
81
82
83            /*
84                Request can only be fulfilled at or after
85                its arrival time.
86
87                Therefore:
88                    max(reachTime, arrivalTime)
89            */
90            long long newTime =
91                max(reachTime, 1LL*arr[i][0]);
92
93
94            // Mark request i as fulfilled.
95            long long newMask =
96                mask | (1LL << i);
97
98
99            /*
100                Now elevator is at request i's floor.
101
102                So i becomes the new "ind".
103            */
104            rec(i, newMask, newTime);
105        }
106    }
107
108
109    long long elevatorRequests(
110        long long n,
111        long long start,
112        vector<vector<int>>& requests
113    ) {
114
115        arr = requests;
116
117        m = arr.size();
118
119
120        /*
121            Fake state representing the initial elevator.
122
123            arr[m] = {0, start}
124        */
125        arr.push_back({0, (int) start});
126
127
128        /*
129            Initially no state has been reached.
130
131            Set dp to a very large value.
132        */
133        memset(dp, 0x3f, sizeof(dp));
134
135
136        /*
137            Start:
138                elevator at 'start'
139                time = 0
140                no requests completed
141        */
142        rec(m, 0, 0);
143
144
145        long long fullMask =
146            (1LL << m) - 1;
147
148
149        long long ans = 1e18;
150
151
152        /*
153            The last completed request can be any request.
154        */
155        for(long long i = 0; i < m; i++) {
156            ans = min(ans, dp[i][fullMask]);
157        }
158
159
160        return ans;
161    }
162};