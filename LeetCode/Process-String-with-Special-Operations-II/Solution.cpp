1class Solution {
2public:
3    char processStr(string s, long long k) {
4        long long l = 0;
5        for(char ch: s){
6            if(ch == '*'){
7                if(l>0) l--;
8            }else if(ch == '#'){
9                l = 2*l;
10            }else if(ch == '%'){
11                continue;
12            }else{
13                l++;
14            }
15        }
16
17        if(k>=l) return '.';
18
19        for(int i=s.size()-1; i>=0; i--){
20            if(s[i] == '*'){
21                l++;
22            }else if(s[i] == '#'){
23                l = l/2;
24                if(k>=l) k = k-l;
25            }else if(s[i] == '%'){
26                k = l-k-1;
27            }else{
28                l--;
29            }
30            if(l == k){
31                return s[i];
32            }
33        }
34
35        return '.';
36
37    }
38};