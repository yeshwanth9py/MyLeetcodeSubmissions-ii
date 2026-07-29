1class Solution {
2public:
3    const long long cap = 1e6+7;
4    long long ncr(long long n, long long R){
5        long long ans = 1;
6        R = min(R, n-R);
7        for(long long r=0; r<R; r++){
8            ans = (1LL*ans*(n-r))/(r+1);
9            if(ans>=cap){
10                ans = cap;
11            }
12        }
13        if(ans>=cap) ans = cap;
14        return ans;
15    }
16
17    int countways(vector<long long> &ump){
18        long long ways = 1;
19        long long tot = 0;
20        for(long long i=0; i<26; i++){
21            if(ump[i]>0){
22                tot+=ump[i];
23            }
24        }
25
26        for(long long i=0; i<26; i++){
27            if(ump[i]>0){
28                ways = 1LL*ways*ncr(tot, ump[i]);
29                if(ways>=cap){
30                    ways = cap;
31                }
32                tot -= ump[i];
33            }
34        }
35
36        return ways;
37    }
38
39    string smallestPalindrome(string s, long long k) {
40        vector<long long> ump(26, 0);
41
42        for(char ch: s){
43            ump[ch-'a']++;
44        }
45
46        char ch = '-';
47        for(long long i=0; i<26; i++){
48            if(ump[i]>0){
49                if(ump[i]%2 == 1){
50                    ch = char('a'+i);
51                }
52                ump[i] = ump[i]/2;
53            }
54        }
55
56        long long tot = s.size()/2;
57
58        string f = "";
59
60        if(countways(ump)<k) return "";
61
62        while(tot>0){
63            for(long long i=0; i<26; i++){
64                if(ump[i]>0){
65                    ump[i]--;
66                    long long ways = countways(ump);
67                    if(ways>=k){
68                        f += char('a'+i);
69                        tot--;
70                        break;
71                    }else{
72                        k -= ways;
73                        ump[i]++;
74                    }
75                }
76            }
77        }
78
79        string sec = f;
80        if(ch != '-'){
81            f = f+ch;
82        }
83        reverse(sec.begin(), sec.end());
84        f = f+sec;
85
86        return f;
87    }
88};