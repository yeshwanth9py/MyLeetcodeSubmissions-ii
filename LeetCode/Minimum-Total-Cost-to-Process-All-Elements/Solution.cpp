1class Solution {
2public:
3    const long long mod = 1e9+7;
4    long long binpow(long long x, long long n, long long mod){
5        if(n == 0) return 1;
6        long long ans = binpow(x, n/2, mod);
7        ans = ((ans*ans)%mod + mod)%mod;
8        if(n&1){
9            ans = ((ans*x)%mod + mod)%mod;
10        }
11        return ans;
12    }
13
14    int minimumCost(vector<int>& nums, long long k) {
15        long long rem = k;
16        long long n = nums.size();
17        long long curc = 0;
18        for(long long i=0; i<n; i++){
19            if(nums[i]<=rem){
20                rem -= nums[i];
21            }else{
22                long long nok = (nums[i]-rem+k-1)/k;
23                curc += nok;
24                curc = (curc%mod + mod)%mod;
25                rem += nok*k;
26                rem -= nums[i];
27            }
28        }
29
30        curc = ((curc*(curc+1))%mod + mod)%mod;
31        curc = ((curc*binpow(2, mod-2, mod))%mod + mod)%mod;
32        return curc;
33    }
34};