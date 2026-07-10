1class Solution {
2public:
3    int next[100100][21];
4    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
5        vector<int> nod2val(n, 0);
6
7        vector<int> val;
8        for(int i=0; i<n; i++){
9            nod2val[i] = nums[i];
10            val.push_back(nums[i]);
11        }
12
13        sort(val.begin(), val.end());
14
15        int i=0;
16        int j=0;
17
18        while(i<n){
19            while(j+1<n && val[j+1]-val[i] <= maxDiff){
20                j++;
21            }
22            next[val[i]][0] = val[j];
23            i++;
24        }
25
26        for(int j=1; j<21; j++){
27            for(int v: val){
28                next[v][j] = next[next[v][j-1]][j-1];
29            }
30        }
31
32        vector<int> ans;
33
34        for(auto q: queries){
35            int u = q[0];
36            int v = q[1];
37
38            int v1 = nod2val[u];
39            int v2 = nod2val[v];
40            // cout<<v1<<" "<<v2<<endl;
41            if(v1>v2) swap(v1, v2);
42            if(v1 == v2){
43                ans.push_back((u == v?0:1));
44            }else{
45                if(next[v1][0]>=v2){
46                    ans.push_back(1);
47                    continue;
48                }
49                int td = 0;
50                for(int j=20; j>=0; j--){
51                    if(next[v1][j]<v2){
52                        v1 = next[v1][j];
53                        td += (1<<j);
54                    }
55                }
56                
57                for(int i=0; i<21; i++){
58                    if(next[v1][i] >= v2){
59                        td += (1<<i);
60                        break;
61                    }
62                }
63                
64                if(td>n){
65                    td = -1;
66                }
67                ans.push_back(td);
68            }
69        }
70
71        return ans;
72    }
73};
74
75