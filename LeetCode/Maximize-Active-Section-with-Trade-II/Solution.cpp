1struct Seg{
2    vector<int> t;
3    Seg(int n, vector<int> &gain){
4        t.resize(4*n, 0);
5        build(1, 0, n-1, gain);
6    }
7
8    void build(int idx, int l, int r, vector<int> &gain){
9        if(l == r){
10            t[idx] = gain[l];
11            return;
12        }
13
14        int mid = (l+r)/2;
15        build(2*idx, l, mid, gain);
16        build(2*idx+1, mid+1, r, gain);
17        t[idx] = max(t[2*idx], t[2*idx+1]);
18    }
19
20    
21    int query(int idx, int l, int r, int ql, int qr){
22        if(r<ql || l>qr) return 0;
23        if(l>=ql && r<=qr){
24            return t[idx];
25        }
26        int mid = (l+r)/2;
27        return max(query(2*idx, l, mid, ql, qr), query(2*idx+1, mid+1, r, ql, qr));
28    }
29};
30
31
32class Solution {
33public:
34    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& q) {
35        int n = s.size();
36        vector<pair<int, int>> ones;
37
38        int tot = 0;
39        int cnt = 0;
40        for(int i=0; i<n; i++){
41            if(s[i] == '0'){
42                if(cnt){
43                    ones.push_back({i-cnt, i-1});
44                }
45                cnt = 0;
46            }else{
47                cnt++;
48                tot++;
49            }
50        }
51
52        ones.push_back({n-cnt, n-1});
53
54        int m = ones.size();
55        vector<int> start(m, 0);
56        vector<int> end(m, 0);
57
58        vector<int> gain(m, 0);
59
60        vector<int> prev0(n, 0);
61        vector<int> next0(n, 0);
62
63        for(int i=0; i<n; i++){
64            prev0[i] = (s[i] == '0');
65            if(i && prev0[i]){
66                prev0[i] += prev0[i-1];
67            }
68        }
69
70        for(int i=n-1; i>=0; i--){
71            next0[i] = (s[i] == '0');
72            if(i+1<n && next0[i]){
73                next0[i] += next0[i+1];
74            } 
75        }
76
77        for(int i=0; i<m; i++){
78            start[i] = ones[i].first;
79            end[i] = ones[i].second;
80
81            int k1 = start[i];
82            int k2 = end[i];
83            if(k1-1>=0 && k2+1<n){
84                gain[i] = prev0[k1-1] + next0[k2+1];
85            }
86        }
87
88        vector<int> bans;
89        Seg sg(m, gain);
90
91        auto getmax = [&](int l1, int rl, int start, int end){
92            int retv = 0;
93            if(start-1>=l1){
94                retv += min(start-l1, prev0[start-1]);
95            }
96
97            if(end+1<=rl){
98                retv += min(rl-end, next0[end+1]);
99            }
100
101            return retv;
102        };
103
104        for(int i=0; i<q.size(); i++){
105            int st = q[i][0];
106            int en = q[i][1];
107
108            int st1 = upper_bound(start.begin(), start.end(), st)-start.begin();
109            int en1 = lower_bound(end.begin(), end.end(), en)-end.begin()-1;
110            if(st1>en1){
111                bans.push_back(tot);
112                continue;
113            }
114
115            int ans = getmax(st, en, ones[st1].first, ones[st1].second);
116            ans = max(ans, getmax(st, en, ones[en1].first, ones[en1].second));
117
118            if(st1+1<=en1-1){
119                ans = max(ans, sg.query(1, 0, m-1, st1+1, en1-1));
120            }
121
122            bans.push_back(tot+ans);
123        }
124
125        return bans;
126    }
127};
128
129
130
131
132
133
134