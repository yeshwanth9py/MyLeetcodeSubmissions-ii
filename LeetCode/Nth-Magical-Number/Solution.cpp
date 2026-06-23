1class Solution {
2public:
3    long long mod = 1e9+7;
4    long long gcd(int a, int b){
5        if(a==0 || b==0){
6            return a+b;
7        }
8        return gcd(b, a%b);
9    }
10
11    long long lcm(long long a, long long b){
12        return (a*b)/(gcd(a, b));
13    }
14
15    bool check(long long md, long long a, long long b, long long n){
16        long long noa = md/a;
17        long long nob = md/b;
18        long long noab = md/lcm(a, b);
19        return noa+nob-noab>=n;
20    }
21
22    int nthMagicalNumber(int n, int a, int b) {
23        long long lo = min(a, b);
24        long long hi = 1LL*n*max(a, b);
25        long long ans = -1;
26        while(lo<=hi){
27            long long mid = (lo+hi)/2;
28            if(check(mid, a, b, n)){
29                ans = mid;
30                hi = mid-1;
31            }else{
32                lo = mid+1;
33            }
34        }
35        return ans%mod;
36    }
37};