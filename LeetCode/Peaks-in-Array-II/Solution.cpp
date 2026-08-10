1struct node{
2    long long ssq;
3    long long nop;
4    long long lp;
5    long long rp;
6    node(long long _ssq = 0, long long _nop = 0, long long _lp = -1, long long _rp = -1){
7        ssq = _ssq;
8        nop = _nop;
9        lp = _lp;
10        rp = _rp;
11    }
12};
13
14long long n;
15vector<int> arr;
16bool ispeak(long long idx){
17    if(idx-1>=0 && idx+1<n && arr[idx]>arr[idx-1] && arr[idx]>arr[idx+1]){
18        return 1;
19    }
20    return 0;
21}
22
23struct Seg{
24    vector<node> t;
25    Seg(long long n){
26        t.resize(4*n);
27    }
28    node merge(node a, node b){
29        if(b.nop == 0) return a;
30        if(a.nop == 0) return b;
31        node c;
32        c.ssq = a.ssq + b.ssq;
33        c.nop = a.nop + b.nop;
34        c.lp = a.lp;
35        c.rp = b.rp;
36        long long d = b.lp - a.rp;
37        c.ssq += (d*d);
38        return c;
39    }
40
41    void build(long long idx, long long l, long long r){
42        if(l == r){
43            if(ispeak(l)){
44                t[idx].ssq = 0;
45                t[idx].lp = l;
46                t[idx].rp = l;
47                t[idx].nop = 1;
48            }
49            return;
50        }
51        long long mid = (l+r)/2;
52        build(2*idx, l, mid);
53        build(2*idx+1, mid+1, r);
54        t[idx] = merge(t[2*idx], t[2*idx+1]);
55    }
56
57    void update(long long idx, long long l, long long r, long long pos, long long val){
58        if(pos<l ||pos>r) return;
59        if(l == r){
60            if(ispeak(l)){
61                t[idx].nop = 1;
62                t[idx].lp = l;
63                t[idx].rp = l;
64                t[idx].ssq = 0;
65            }else{
66                t[idx] = node();
67            }
68            return;
69        }
70        long long mid = (l+r)/2;
71        update(2*idx, l, mid, pos, val);
72        update(2*idx+1, mid+1, r, pos, val);
73        t[idx] = merge(t[2*idx], t[2*idx+1]);
74    }
75
76    node query(long long idx, long long l, long long r, long long ql, long long qr){
77        if(r<ql || qr<l) return node();
78        if(ql<=l && r<=qr){
79            return t[idx];
80        }
81        long long mid = (l+r)/2;
82        return merge(query(2*idx, l, mid, ql, qr), query(2*idx+1, mid+1, r, ql, qr));
83    }
84};
85
86
87class Solution {
88public:
89    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
90        n = nums.size();
91        arr = nums;
92
93        Seg sg(n);
94        sg.build(1, 0, n-1);
95
96        vector<long long> ans;
97
98        for(auto q: queries){
99            long long ty = q[0];
100            long long l = q[1];
101            long long r = q[2];
102            if(ty == 1){
103                long long t1 = r-l;
104                auto retv = sg.query(1, 0, n-1, l+1, r-1);
105                if(retv.nop == 0){
106                    ans.push_back(0);
107                    continue;
108                }
109                long long t21 = (l-retv.lp)*(l-retv.lp);
110                long long t22 = (r-retv.rp)*(r-retv.rp);
111                long long t23 = retv.ssq;
112                ans.push_back(((t1*t1) - t21 - t22 - t23)/2);
113            }else{
114                arr[l] = r;
115                if(l-1>=0 && arr[l]>arr[l-1] && l+1<n && arr[l]>arr[l+1]){
116                    sg.update(1, 0, n-1, l, 1);
117                }else{
118                    sg.update(1, 0, n-1, l, 0);
119                }
120
121                if(l-2>=0 && arr[l-1]>arr[l-2] && arr[l-1]>arr[l]){
122                    sg.update(1, 0, n-1, l-1, 1);
123                }else{
124                    sg.update(1, 0, n-1, l-1, 0);
125                }
126
127                if(l+2<n && arr[l+1]>arr[l+2] && arr[l+1]>arr[l]){
128                    sg.update(1, 0, n-1, l+1, 1);
129                }else{
130                    sg.update(1, 0, n-1, l+1, 0);
131                }
132            }
133        }
134
135        return ans;
136    }
137};