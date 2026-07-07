1class Solution {
2public:
3    long long sumAndMultiply(int n) {
4        int sm = 0;
5        string s = "";
6        while(n>0){
7            int ld = n%10;
8            if(ld != 0){
9                s.push_back(ld+'0');
10                sm += ld;
11            }
12            n = n/10;
13        }
14        int val = 0;
15        if(s!=""){
16            reverse(s.begin(), s.end());
17            val = stoll(s);
18        }
19        return (1LL*val*sm);
20    }
21};