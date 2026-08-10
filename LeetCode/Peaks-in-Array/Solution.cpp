1struct Seg{
2    vector<int> t;
3    Seg(int n){
4        t.resize(4*n, 0);
5    }
6    void update(int idx, int l, int r, int pos, int val){
7        if(pos<l || pos>r) return;
8        if(l == r){
9            t[idx] = val;
10            return;
11        }
12        int mid = (l+r)/2;
13        update(2*idx, l, mid, pos, val);
14        update(2*idx+1, mid+1, r, pos, val);
15        t[idx] = t[2*idx] + t[2*idx+1];
16    }
17
18    int query(int idx, int l, int r, int ql, int qr){
19        if(r<ql || qr<l) return 0;
20        if(ql>qr) return 0;
21        if(l>=ql && r<=qr) return t[idx];
22        int mid = (l+r)/2;
23        return query(2*idx, l, mid, ql, qr) + query(2*idx+1, mid+1, r, ql, qr);
24    }
25};
26
27
28class Solution {
29public:
30    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
31        int n = nums.size();
32        Seg sg(n);
33
34        for(int i=1; i<n-1; i++){
35            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
36                sg.update(1, 0, n-1, i, 1);
37            }
38        }
39
40        vector<int> ans;
41        for(auto q: queries){
42            int ty = q[0];
43            int l = q[1];
44            int r = q[2];
45            if(ty == 1){
46                int cur = sg.query(1, 0, n-1, l+1, r-1);
47                ans.push_back(cur);
48            }else{  
49                nums[l] = r;
50                if(l-1>=0 && nums[l]>nums[l-1] && l+1<n && nums[l]>nums[l+1]){
51                    sg.update(1, 0, n-1, l, 1);
52                }else{
53                    sg.update(1, 0, n-1, l, 0);
54                }
55
56                if(l-2>=0 && nums[l-1]>nums[l-2] && nums[l-1]>nums[l]){
57                    sg.update(1, 0, n-1, l-1, 1);
58                }else{
59                    sg.update(1, 0, n-1, l-1, 0);
60                }
61
62                if(l+2<n && nums[l+1]>nums[l+2] && nums[l+1]>nums[l]){
63                    sg.update(1, 0, n-1, l+1, 1);
64                }else{
65                    sg.update(1, 0, n-1, l+1, 0);
66                }
67            }
68        }
69
70        return ans;
71
72
73
74    }
75};