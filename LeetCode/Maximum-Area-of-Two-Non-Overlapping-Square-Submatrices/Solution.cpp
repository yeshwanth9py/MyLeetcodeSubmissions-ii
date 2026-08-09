1class Solution {
2public:
3    int maxArea(vector<vector<int>>& mat) {
4        int n = mat.size();
5        int m = mat[0].size();
6
7        vector<vector<int>> pref(n, vector<int>(m, 0));
8
9        for(int i=0; i<n; i++){
10            for(int j=0; j<m; j++){
11                pref[i][j] = mat[i][j];
12                pref[i][j] += (i-1>=0?pref[i-1][j]:0) + (j-1>=0?pref[i][j-1]:0) - ((i-1>=0 && j-1>=0)?pref[i-1][j-1]:0);
13            }
14        }
15
16        if(pref[n-1][m-1] <= 1) return 0;
17
18        auto check = [&](int mid){
19            vector<int> col(m, 0);
20            vector<int> row(n, 0);
21            int des = mid*mid;
22            for(int i=n-1; i>=0; i--){
23                for(int j=m-1; j>=0; j--){
24                    int ii = i + mid - 1;
25                    int jj = j + mid - 1;
26                    if(ii<n && jj<m){
27                        int curar = pref[ii][jj] - (i-1>=0?pref[i-1][jj]:0) - (j-1>=0?pref[ii][j-1]:0) + ((i-1>=0 && j-1>=0)?pref[i-1][j-1]:0); 
28                        if(curar == des){
29                            row[i] = 1;
30                            col[j] = 1;
31                        }
32                    }
33                }
34            }
35
36            for(int i=n-2; i>=0; i--){
37                row[i] |= row[i+1];
38            }
39
40            for(int i=m-2; i>=0; i--){
41                col[i] |= col[i+1];
42            }
43
44            for(int i=0; i<n; i++){
45                for(int j=0; j<m; j++){
46                    int ii = i + mid - 1;
47                    int jj = j + mid - 1;
48                    if(ii<n && jj<m){
49                        int curar = pref[ii][jj] - (i-1>=0?pref[i-1][jj]:0) - (j-1>=0?pref[ii][j-1]:0) + ((i-1>=0 && j-1>=0)?pref[i-1][j-1]:0); 
50                        if(curar == des){
51                            if((jj+1<m && col[jj+1]) || (ii+1<n && row[ii+1])){
52                                return 1;
53                            }
54                        }
55                    }
56                }
57            }
58
59            return 0;
60        };
61
62        int lo = 1;
63        int hi = min(n, m);
64        int ans = 1;
65        while(lo<=hi){
66            int mid = (lo+hi)/2;
67            if(check(mid)){
68                ans = mid;
69                lo = mid+1;
70            }else{
71                hi = mid-1;
72            }
73        }
74
75        return ans*ans;
76        
77
78        
79    }
80    
81};