1class Solution {
2public:
3    bool sumGame(string s) {
4        int n = s.size();
5        int s1 = 0;
6        int s2 = 0;
7        int q1 = 0;
8        int q2 = 0;
9        for(int i=0; i<n; i++){
10            if(i<(n/2)){
11                if(s[i] == '?'){
12                    q1++;
13                    continue;
14                }
15                s1 += s[i]-'0';
16            }else{
17                if(s[i] == '?'){
18                    q2++;
19                    continue;
20                }
21                s2 += s[i]-'0';
22            }
23        }
24
25        if((s1-s2)*2 == 9*(q2-q1)){
26            return 0;
27        }
28        return 1;
29    }
30};