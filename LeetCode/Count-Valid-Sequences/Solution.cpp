1long long fact[500022];
2long long invfact[500022];
3const long long mod = 1e9+7;
4
5
6long long binpow(long long x, long long n, long long mod){
7    if(n == 0) return 1;
8    long long ans = binpow(x, n/2, mod);
9    ans = ((ans*ans)%mod + mod)%mod;
10    if(n%2){
11        ans = ((ans*x)%mod + mod)%mod;
12    }
13    return ans;
14}
15
16struct Comb{
17    void preFact(){
18        fact[0] = fact[1] = 1;
19        for(long long i=2; i<500022; i++){
20            fact[i] = ((fact[i-1]*i)%mod + mod)%mod;
21        }
22        
23        invfact[500022-1] = binpow(fact[500022-1], mod-2, mod);
24        for(long long i=500022-2; i>=0; i--){
25            invfact[i] = ((invfact[i+1]*(i+1))%mod + mod)%mod;
26        }
27    }
28    Comb(){
29        preFact();
30    }
31};
32
33static Comb cb;
34
35long long ncr(long long n, long long r){
36    if(r<0 || r>n) return 0;
37    long long num = fact[n];
38    long long den = ((invfact[n-r] * invfact[r])%mod + mod)%mod;
39    num = ((num*den)%mod + mod)%mod;
40    return num;
41}
42
43
44
45
46
47class Solution {
48public:
49    // Solution(){
50    //     // if(cnt == 1) return;
51    //     // cnt++;
52    //     preFact();
53    // }
54
55    int countValidSequences(long long n, long long k) {
56        if(n<k) return 0;
57        // preFact();
58        long long tot = ncr(n-1, k-1);
59        if(n%2 == k%2 && n>=k){
60            long long extra = (n-k)/2;
61            extra = ncr(extra+k-1, k-1);
62            tot = (tot-extra+mod)%mod;
63        }
64
65        return tot;
66    }
67};
68
69
70
71
72
73