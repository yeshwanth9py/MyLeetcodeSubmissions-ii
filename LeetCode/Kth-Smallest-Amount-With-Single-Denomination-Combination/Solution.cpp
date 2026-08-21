1class Solution {
2public:
3    long long findKthSmallest(vector<int>& arr, long long k) {
4        long long n = arr.size();
5        auto check = [&](long long md){
6            long long ans = 0;
7            for(long long mask=1; mask<(1<<n); mask++){
8                long long l = 1;
9                for(long long i=0; i<n; i++){
10                    if((mask&(1<<i)) != 0){
11                        long long g = __gcd(l, 1LL*arr[i]);
12                        l = (arr[i]*l)/g;
13                    }
14                }
15                long long cnt = __builtin_popcount(mask);
16                if(cnt%2 == 1){
17                    ans += md/l;
18                }else{
19                    ans -= md/l;
20                }
21            }
22
23            return ans>=k;
24        };
25
26        long long lo = *min_element(arr.begin(), arr.end());
27        long long hi = lo*k;
28        long long ans = hi;
29        while(lo<=hi){
30            long long mid = (lo+hi)/2;
31            if(check(mid)){
32                ans = mid;
33                hi = mid-1;
34            }else{
35                lo = mid+1;
36            }
37        }
38
39        return ans;
40    }
41};