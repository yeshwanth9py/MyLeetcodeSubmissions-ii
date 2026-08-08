1class Solution {
2public:
3    vector<int> validSequence(string s1, string s2) {
4        int n = s1.size();
5        int m = s2.size();
6
7        vector<int> pref(n, 0);
8        vector<int> suf(n, 0);
9
10        int j = 0;
11
12        // pref[i] = how many characters of s2
13        // we can match before index i
14        for(int i = 0; i < n; i++){
15            pref[i] = j;
16
17            if(j < m && s1[i] == s2[j]){
18                j++;
19            }
20        }
21
22        j = m - 1;
23        int cnt = 0;
24
25        // suf[i] = how many characters at the END of s2
26        // we can match using positions AFTER i
27        for(int i = n - 1; i >= 0; i--){
28            suf[i] = cnt;
29
30            if(j >= 0 && s1[i] == s2[j]){
31                j--;
32                cnt++;
33            }
34        }
35
36        // Try every possible FIRST index.
37        for(int ind = 0; ind < n; ind++){
38
39            if(pref[ind] + suf[ind] + 1 >= m ||
40               pref[ind] + suf[ind] >= m - 1){
41
42                vector<int> ans;
43
44                // Match before ind
45                int k = 0;
46
47                for(int i = 0; i < ind; i++){
48                    if(k < m && s1[i] == s2[k]){
49                        ans.push_back(i);
50                        k++;
51                    }
52                }
53
54                // ind is our first selected index.
55                ans.push_back(ind);
56                k++;
57
58                // Have we already used the mismatch?
59                bool used = (s1[ind] != s2[pref[ind]]);
60
61                // Select the remaining characters.
62                for(int i = ind + 1; i < n && k < m; i++){
63
64                    // If it matches normally, take it.
65                    if(s1[i] == s2[k]){
66                        ans.push_back(i);
67                        k++;
68                    }
69
70                    // Otherwise use this as the one mismatch,
71                    // BUT only if the suffix after i can finish
72                    // the remaining characters.
73                    else if(!used && suf[i] >= m - k - 1){
74                        ans.push_back(i);
75                        k++;
76                        used = true;
77                    }
78                }
79
80                if(k == m)
81                    return ans;
82            }
83        }
84
85        return {};
86    }
87};