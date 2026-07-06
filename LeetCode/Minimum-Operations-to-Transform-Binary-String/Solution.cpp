1class Solution {
2public:
3    int n;
4    string s1, s2;
5    int dp[100011][2];
6    int rec(int ind, int prev){
7        if(ind == n){
8            return 0;
9        }
10        if(dp[ind][prev] != -1) return dp[ind][prev];
11        int ways = 1e9;
12        if(s1[ind] == '0'){
13            if(s2[ind] == '0'){
14                ways = min(ways, rec(ind+1, 0));
15            }else{
16                ways = min(ways, 1+rec(ind+1, 1));
17            }
18        }else{
19            if(s2[ind] == '1'){
20                ways = min(ways,  rec(ind+1, 1));
21            }else{
22                if(prev == 1){
23                    ways = min(ways, 2+rec(ind+1, 0));
24                }else if((ind>0 && prev == 0)){
25                    ways = min(ways, 2+rec(ind+1, 0));
26                }
27
28                if(ind+1<n && s1[ind+1] == '1'){
29                    if(s2[ind+1] == '0'){
30                        ways = min(ways, 1+rec(ind+2, 0));
31                    }else{
32                        ways = min(ways, 2+rec(ind+2, 1));
33                    }
34                }else if(ind+1<n && s1[ind+1] == '0'){
35                    if(s2[ind+1] == '0'){
36                        ways = min(ways, 2+rec(ind+2, 0));
37                    }else{
38                        ways = min(ways, 3+rec(ind+2, 1));
39                    }
40                }
41            }
42        }
43
44        return dp[ind][prev] = ways;
45    }
46
47    int minOperations(string s11, string s22) {
48        s1 = s11;
49        s2 = s22;
50        n = s1.size();
51        memset(dp, -1, sizeof(dp));
52        int asn = rec(0, 0);
53        if(asn>=1e8) return -1;
54        return asn;
55    }
56};