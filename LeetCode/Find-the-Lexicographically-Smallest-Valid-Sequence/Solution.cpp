1class Solution {
2public:
3    int n, m;
4    vector<int> validSequence(string w1, string w2) {
5        n = w1.size();
6        m = w2.size();
7
8        vector<int> pref(n, 0);
9        vector<int> suff(n, 0);
10
11        int i = 0;
12        for(int j=0; j<w1.size(); j++){
13            pref[j] = i;
14            if(i<n && w2[i] == w1[j]){
15                i++;
16            }
17        }
18
19        i=w2.size()-1;
20        int cnt = 0;
21        for(int j=w1.size()-1; j>=0; j--){
22            if(i>=0 && w2[i] == w1[j]){
23                cnt++;
24                i--;
25            }
26            suff[j] = cnt;
27        }
28
29        auto printans = [&](int ind){
30            vector<int> ans;
31            int j = 0;
32            // bool ch = 1;
33
34            for(int i=0; i<ind; i++){
35                if(w1[i] == w2[j]){
36                    ans.push_back(i);
37                    j++;
38                }
39            }
40            
41
42            if(j == m){
43                return ans;
44            }
45
46            bool ch = 1;
47
48            if(w1[ind] == w2[j]){
49                ans.push_back(ind);
50                j++;
51            }else{
52                ans.push_back(ind);
53                j++;
54                ch = 0;
55            }
56
57            for(int i=ind+1; i<n; i++){
58                if(j<m && w1[i] == w2[j]){
59                    ans.push_back(i);
60                    j++;
61                }else if(j<m && ch == 1){
62                    ans.push_back(i);
63                    ch = 0;
64                    j++;
65                }
66            }
67
68            if(j>=m) return ans;
69
70            vector<int> retv;
71            return retv;
72        };
73
74        for(int i=0; i<n; i++){
75            if(pref[i] + suff[i] >= m-1){
76                vector<int> retv =  printans(i);
77                cout<<i<<" ";
78                if(retv.size() != 0) return retv;
79            }
80        }
81
82        return {};
83    }
84};