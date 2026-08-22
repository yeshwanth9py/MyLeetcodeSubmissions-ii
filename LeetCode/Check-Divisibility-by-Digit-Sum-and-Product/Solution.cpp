1class Solution {
2public:
3    bool checkDivisibility(int n) {
4        int sm = 0;
5        int pr = 1;
6        int dn = n;
7        while(n>0){
8            int ld = n%10;
9            sm += ld;
10            pr = pr*ld;
11            n = n/10;
12        }
13
14        return (dn%(sm+pr) == 0);
15    }
16};