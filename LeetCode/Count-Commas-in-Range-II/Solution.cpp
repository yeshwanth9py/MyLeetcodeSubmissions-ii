1class Solution {
2public:
3    long long countCommas(long long n) {
4        if(n<1000) return 0;
5        long long mul = 1e3;
6        long long ans = 0;
7        while(n>=mul){
8            ans += (n-mul+1);
9            mul = mul*1e3;
10        }
11        return ans;
12    }
13};