1struct node{
2    int l=0;
3    int r=0;
4    int ind = 0;
5};
6
7
8class Solution {
9public:
10    vector<bool> validSubarrays(vector<int>& arr, int k, vector<vector<int>>& q) {
11        vector<node> que;
12        int ind = 0;
13        for(auto el: q){
14            int l = el[0];
15            int r = el[1];
16            que.push_back({l, r, ind});
17            ind++;
18        }
19        int n = arr.size();
20        int sz = sqrt(n);
21
22        sort(que.begin(), que.end(), [&](node &a, node &b){
23            int id1 = a.l/sz;
24            int id2 = b.l/sz;
25            if(id1 != id2){
26               return id1<id2; 
27            }
28            return a.r>b.r;
29        });
30
31        unordered_map<int, int> ump;
32        int nod = 0;
33        
34        int i=0;
35        vector<bool> ans(que.size(), 0);
36        int l = -1;
37        int r = -1;
38
39        int noodd = 0;
40
41        auto add = [&](int ind){
42            if(ind<0) return;
43            if(ind>=n) return;
44            ump[arr[ind]]++;
45            if(ump[arr[ind]] == 1){
46                nod++;
47                noodd++;
48            }else{
49                if(ump[arr[ind]]%2 == 0){
50                    noodd--;
51                }else{
52                    noodd++;
53                }
54            }
55        };
56
57        auto remove = [&](int ind){
58            if(ind<0 || ind>=n) return;
59            ump[arr[ind]]--;
60            if(ump[arr[ind]] == 0){
61                nod--;
62                noodd--;
63            }else{
64                if(ump[arr[ind]]%2==0){
65                    noodd--;
66                }else{
67                    noodd++;
68                }
69            }
70        };
71
72        while(i<que.size()){
73            int ll = que[i].l;
74            int rr = que[i].r;
75            int ind = que[i].ind;
76
77            while(l<ll){
78                remove(l);
79                l++;
80            }
81
82            while(r<rr){
83                r++;
84                add(r);
85            }
86
87            while(l>ll){
88                l--;
89                add(l);
90            }
91
92            while(r>rr){
93                remove(r);
94                r--;
95            }
96
97            ans[ind] = (nod == k && noodd == 0);
98            i++;
99        }
100
101        return ans;        
102    }
103};