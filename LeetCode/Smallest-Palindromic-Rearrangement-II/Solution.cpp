1class Solution {
2public:
3    const int cap =  1e6+6;
4    int ncr(int n, int r){
5        if(r == 0) return 1;
6        r = min(r, n-r);
7        long long ans = 1;
8        for(int i=0; i<r; i++){
9            ans = (1LL*ans*(n-i))/(i+1);
10            if(ans>=cap){
11                ans = cap;
12            }
13        }
14        return ans;
15    }
16
17    int countways(vector<int> &ump){
18        int tot = 0;
19        for(int i=0; i<26; i++){
20            if(ump[i]>0){
21                tot += ump[i];
22            }
23        }
24
25        long long ways = 1;
26        for(int i=0; i<26; i++){
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
39    string smallestPalindrome(string s, int k) {
40        vector<int> ump(26, 0);
41        for(char ch: s){
42            ump[ch-'a']++;
43        }
44        int tot = s.size();
45        char ext = '-';
46        for(int i=0; i<26; i++){
47            if(ump[i]%2 == 1){
48                ext = char('a'+i);
49            }
50            ump[i] = ump[i]/2;
51        }
52
53        if(countways(ump)<k) return "";
54
55        int rem = tot/2;
56        string first = "";
57        while(rem>0){
58            for(int i=0; i<26; i++){
59                if(ump[i]){
60                    ump[i]--;
61                    int ways = countways(ump);
62                    if(ways>=k){
63                        first += char('a'+i);
64                        rem--;
65                        break;
66                    }else{
67                        k -= ways;
68                        ump[i]++;
69                    }
70                }
71            }
72        }
73
74
75        string sec = first;
76        reverse(sec.begin(), sec.end());
77        if(ext != '-'){
78            first += ext;
79        }
80
81        first = first+sec;
82
83        return first;
84    }
85};