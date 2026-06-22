1class Solution {
2public:
3    int mySqrt(int x) {
4        long long lo = 0;
5        long long hi = x;
6        long long ans = 0;
7        while(lo<=hi){
8            long long mid = (lo+hi)/2;
9            if(mid*mid <= x){
10                ans = mid;
11                lo = mid+1;
12            }else{
13                hi = mid-1;
14            }
15        }
16
17        return ans;
18    }
19};