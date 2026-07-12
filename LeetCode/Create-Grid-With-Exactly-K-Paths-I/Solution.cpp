1class Solution {
2public:
3    vector<string> createGrid(int n, int m, int k) {
4        vector<string> vec(n);
5
6        for(int i=0; i<n; i++){
7            string temp = "";
8            for(int j=0; j<m; j++){
9                temp.push_back('#');
10            }
11            vec[i] = temp;
12        }
13
14        
15        
16        if(k == 1){
17            for(int i=0; i<n; i++){
18                vec[i][0] = '.';
19            }
20            for(int i=0; i<m; i++){
21                vec[n-1][i] = '.';
22            }
23            return vec;
24        }
25
26        if(m == 1 || n == 1) return {};
27
28        for(int i=0; i<n; i++){
29            vec[i][0] = '.';
30        }
31        for(int i=0; i<m; i++){
32            vec[n-1][i] = '.';
33        }
34
35        if(m == 2){
36            if(n<k) return {};
37            if(k == 2){
38                vec[n-2][1] = '.';
39                return vec;
40            }
41            if(k == 3){
42                vec[n-2][1] = '.';
43                vec[n-3][1] = '.';
44                return vec;
45            }
46
47            if(k == 4){
48                vec[n-2][1] = '.';
49                vec[n-3][1] = '.';
50                vec[n-4][1] = '.';
51                return vec;
52            }
53        }
54
55        if(m == 3){
56            if(k == 2){
57                if(n<2) return {};
58                vec[n-2][1] = '.';
59                return vec;
60            }
61            if(k == 3){
62                if(n<2) return {};
63                vec[n-2][1] = '.';
64                vec[n-2][2] = '.';
65                return vec;
66            }
67
68            if(k == 4){
69                if(n<3) return {};
70                vec[n-1][0] = '#';
71                vec[n-2][1] = '.';
72                vec[n-3][1] = '.';
73                vec[n-2][2] = '.';
74                return vec;
75            }
76        }
77
78        if(m == 4){
79            if(k == 2){
80                if(n<2) return {};
81                vec[n-2][1] = '.';
82                return vec;
83            }
84            if(k == 3){
85                if(n<2) return {};
86                vec[n-2][1] = '.';
87                vec[n-2][2] = '.';
88                return vec;
89            }
90
91            if(k == 4){
92                if(n<2) return {};
93                vec[n-2][1] = '.';
94                vec[n-2][2] = '.';
95                vec[n-2][3] = '.';
96                return vec;
97            }
98        }
99
100        if(k == 2){
101            vec[n-2][1] = '.';
102            return vec;
103        }
104
105        if(k == 3){
106            vec[n-2][1] = '.';
107            vec[n-2][2] = '.';
108            return vec;
109        }
110
111        if(k == 4){
112            vec[n-2][1] = '.';
113            vec[n-2][2] = '.';
114            vec[n-2][3] = '.';
115            return vec;
116        }
117
118        return vec;
119
120    }
121};