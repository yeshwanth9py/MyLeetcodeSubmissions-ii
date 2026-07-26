1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5    static constexpr int MAX_N = 500000;
6    static constexpr long long MOD = 1'000'000'007LL;
7
8    struct Combinations {
9        long long fact[MAX_N + 1];
10        long long invFact[MAX_N + 1];
11
12        long long binaryPower(long long base, long long exponent) {
13            long long answer = 1;
14
15            while (exponent > 0) {
16                if (exponent & 1) {
17                    answer = answer * base % MOD;
18                }
19
20                base = base * base % MOD;
21                exponent >>= 1;
22            }
23
24            return answer;
25        }
26
27        Combinations() {
28            fact[0] = 1;
29
30            for (int i = 1; i <= MAX_N; i++) {
31                fact[i] = fact[i - 1] * i % MOD;
32            }
33
34            invFact[MAX_N] =
35                binaryPower(fact[MAX_N], MOD - 2);
36
37            for (int i = MAX_N; i >= 1; i--) {
38                invFact[i - 1] =
39                    invFact[i] * i % MOD;
40            }
41        }
42
43        long long nCr(int n, int r) {
44            if (r < 0 || r > n) {
45                return 0;
46            }
47
48            return fact[n]
49                * invFact[r] % MOD
50                * invFact[n - r] % MOD;
51        }
52    };
53
54    // Created once for the program, not once per Solution object.
55    inline static Combinations comb;
56
57public:
58    int countValidSequences(long long n, long long k) {
59        if (n < k) {
60            return 0;
61        }
62
63        // All compositions of n into k positive elements.
64        long long answer =
65            comb.nCr(n - 1, k - 1);
66
67        // An all-odd sequence is possible only when n-k is even.
68        if ((n - k) % 2 == 0) {
69            long long remaining = (n - k) / 2;
70
71            long long allOdd =
72                comb.nCr(remaining + k - 1, k - 1);
73
74            answer = (answer - allOdd + MOD) % MOD;
75        }
76
77        return static_cast<int>(answer);
78    }
79};