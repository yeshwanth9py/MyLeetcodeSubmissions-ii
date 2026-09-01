1class Solution {
2public:
3    int dp[21][21][1<<11];  // maximum energy for this state
4
5    unordered_map<int, int> ump;
6
7    int dx[4] = {1, 0, -1, 0};
8    int dy[4] = {0, 1, 0, -1};
9
10    int minMoves(vector<string>& arr, int e) {
11
12        int m = arr[0].size();
13        int n = arr.size();
14
15        int sx = 0;
16        int sy = 0;
17
18        for(int i = 0; i < arr.size(); i++){
19            for(int j = 0; j < arr[i].size(); j++){
20
21                if(arr[i][j] == 'L'){
22                    int ind = (i*m + j);
23                    ump[ind] = 1;
24                }
25                else if(arr[i][j] == 'S'){
26                    sx = i;
27                    sy = j;
28                }
29            }
30        }
31
32        int ind = 0;
33
34        for(auto &el : ump){
35            el.second = ind++;
36        }
37
38        int mind = ind;
39
40        priority_queue<
41            vector<int>,
42            vector<vector<int>>,
43            greater<vector<int>>
44        > pq;
45
46        memset(dp, -1, sizeof(dp));
47
48        dp[sx][sy][0] = e;
49
50        // {moves, x, y, mask, energy}
51        pq.push({0, sx, sy, 0, e});
52
53        while(!pq.empty()){
54
55            auto tel = pq.top();
56            pq.pop();
57
58            int moves = tel[0];
59            int x = tel[1];
60            int y = tel[2];
61            int mask = tel[3];
62            int ce = tel[4];
63
64            // This state is outdated
65            if(ce < dp[x][y][mask])
66                continue;
67
68            if(mask == (1 << mind) - 1)
69                return moves;
70
71            if(arr[x][y] == 'R')
72                ce = e;
73
74            for(int i = 0; i < 4; i++){
75
76                int nx = x + dx[i];
77                int ny = y + dy[i];
78
79                if(nx < 0 || ny < 0 ||
80                   nx >= n || ny >= m ||
81                   ce == 0 ||
82                   arr[nx][ny] == 'X')
83                    continue;
84
85                int nmask = mask;
86
87                if(arr[nx][ny] == 'L'){
88                    int ind = ump[(nx*m) + ny];
89                    nmask = mask | (1 << ind);
90                }
91
92                int ne = ce - 1;
93
94                // Only push if we reached this state
95                // with MORE energy.
96                if(ne > dp[nx][ny][nmask]){
97                    dp[nx][ny][nmask] = ne;
98
99                    pq.push({
100                        moves + 1,
101                        nx,
102                        ny,
103                        nmask,
104                        ne
105                    });
106                }
107            }
108        }
109
110        return -1;
111    }
112};