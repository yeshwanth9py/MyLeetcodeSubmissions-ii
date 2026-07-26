1long long fact[500022];
2long long invfact[500022];
3const long long mod = 1e9+7;
4
5int cnt = 0;
6
7long long binpow(long long x, long long n, long long mod){
8    if(n == 0) return 1;
9    long long ans = binpow(x, n/2, mod);
10    ans = ((ans*ans)%mod + mod)%mod;
11    if(n%2){
12        ans = ((ans*x)%mod + mod)%mod;
13    }
14    return ans;
15}
16
17
18void preFact(){
19    fact[0] = fact[1] = 1;
20    for(long long i=2; i<500022; i++){
21        fact[i] = ((fact[i-1]*i)%mod + mod)%mod;
22    }
23    
24    invfact[500022-1] = binpow(fact[500022-1], mod-2, mod);
25    for(long long i=500022-2; i>=0; i--){
26        invfact[i] = ((invfact[i+1]*(i+1))%mod + mod)%mod;
27    }
28}
29
30long long ncr(long long n, long long r){
31    if(r<0 || r>n) return 0;
32    long long num = fact[n];
33    long long den = ((invfact[n-r] * invfact[r])%mod + mod)%mod;
34    num = ((num*den)%mod + mod)%mod;
35    return num;
36}
37
38
39class Solution {
40public:
41    Solution(){
42        if(cnt == 1) return;
43        cnt++;
44        preFact();
45    }
46    int countValidSequences(long long n, long long k) {
47        if(n<k) return 0;
48        long long tot = ncr(n-1, k-1);
49        if(n%2 == k%2 && n>=k){
50            long long extra = (n-k)/2;
51            extra = ncr(extra+k-1, k-1);
52            tot = (tot-extra+mod)%mod;
53        }
54
55        return tot;
56    }
57};