1class Solution {
2public:
3    const long long mod = 1e9+7;
4    int distinctSubseqII(string s) {
5        long long n = s.size();
6        vector<long long> prev(26, -1);
7        vector<long long> freq(n+1, 0);
8        freq[0] = 1;
9        for(long long i=1; i<=n; i++){
10            long long ch = s[i-1]-'a';
11            if(prev[ch] == -1){
12                freq[i] = ((2*freq[i-1])%mod + mod)%mod;
13            }else{
14                freq[i] = ((2*freq[i-1])%mod + mod)%mod;
15                long long pr = freq[prev[ch]-1];
16                freq[i] -= pr;
17                freq[i] = (freq[i]+mod)%mod;
18            }
19            prev[ch] = i;
20        }
21
22        return (freq[n]-1+mod)%mod;
23    }
24};