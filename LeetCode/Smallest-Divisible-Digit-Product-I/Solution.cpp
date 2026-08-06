1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        for(int dnum=n; dnum<1e6; dnum++){
5            int pr = 1;
6            int num = dnum;
7            while(num>0){
8                int ld = num%10;
9                num = num/10;
10                pr = pr*ld;
11                pr = pr%t;
12            }
13            if(pr == 0) return dnum;
14        }
15
16        return 1e6;
17    }
18};