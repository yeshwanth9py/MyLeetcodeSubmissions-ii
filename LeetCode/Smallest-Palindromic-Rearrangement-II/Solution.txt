1#include <algorithm>
2#include <string>
3#include <vector>
4using namespace std;
5
6class Solution {
7public:
8    // Helper: Compute n choose k but "cap" the result to cap.
9    // That is, if the computed value exceeds cap, return cap.
10    unsigned long long nCkCapped(int n, int k, unsigned long long cap) {
11        if (k > n) return 0;
12        if (k > n - k) k = n - k;  // use symmetry
13        unsigned long long res = 1;
14        for (int i = 1; i <= k; i++) {
15            // Multiply res by (n - i + 1) first, then divide by i.
16            res = res * (n - i + 1) / i;
17            if (res > cap) return cap;
18        }
19        return res;
20    }
21    
22    // Helper: Compute multinomial coefficient for a multiset.
23    // total: total number of items,
24    // count: frequency array for letters,
25    // cap: the maximum value (if result exceeds cap, we return cap).
26    unsigned long long multinomialCapped(const vector<int>& count, int total, unsigned long long cap) {
27        unsigned long long res = 1;
28        int rem = total;
29        for (int c : count) {
30            if (c > 0) {
31                unsigned long long ways = nCkCapped(rem, c, cap);
32                // Multiply res and cap the result.
33                if (res > cap / ways) return cap;
34                res *= ways;
35                rem -= c;
36                if (res > cap) return cap;
37            }
38        }
39        return res;
40    }
41    
42    // Given the multiset described by leftCount with total size "total",
43    // compute the kth lexicographical permutation.
44    // All computations compare values with k, so we only care if counts exceed k.
45    string kthPermutationForMultiset(const vector<int>& initCount, int total, unsigned long long k) {
46        vector<int> count = initCount;  // copy the frequency count
47        string result;
48        for (int pos = 0; pos < total; pos++) {
49            // Try each candidate letter in lexicographical order.
50            for (int letter = 0; letter < 26; letter++) {
51                if (count[letter] == 0) continue;
52                count[letter]--; // choose this letter tentatively
53                // Compute number of distinct arrangements for the remaining positions.
54                unsigned long long ways = multinomialCapped(count, total - pos - 1, k);
55                if (k > ways) {
56                    // kth permutation is not in this block; skip it.
57                    k -= ways;
58                    count[letter]++; // restore the count
59                } else {
60                    // This letter is fixed at the current position.
61                    result.push_back('a' + letter);
62                    break;
63                }
64            }
65        }
66        return result;
67    }
68    
69    // Main function: Given a palindromic string s and integer k,
70    // return the kth lexicographically smallest palindromic permutation.
71    // If there are fewer than k distinct palindromic permutations, return an empty string.
72    // The left half is stored in the variable prelunthak.
73    string smallestPalindrome(string s, unsigned long long k) {
74        int n = s.size();
75        vector<int> freq(26, 0);
76        for (char c : s) {
77            freq[c - 'a']++;
78        }
79        
80        string prelunthak; // left half
81        string mid;       // middle character (if any)
82        for (int i = 0; i < 26; i++) {
83            if (freq[i] % 2 != 0) {
84                // More than one odd frequency would yield no valid palindrome.
85                if (!mid.empty()) return "";
86                mid = string(1, 'a' + i);
87            }
88            prelunthak.append(freq[i] / 2, 'a' + i);
89        }
90        
91        // Compute the frequency of letters in prelunthak.
92        vector<int> leftCount(26, 0);
93        for (char c : prelunthak)
94            leftCount[c - 'a']++;
95        int leftSize = prelunthak.size();
96        
97        // Compute total number of distinct permutations for the left half,
98        // but cap the result at k so we don't overflow.
99        unsigned long long totalPerm = multinomialCapped(leftCount, leftSize, k);
100        if (k < 1 || k > totalPerm)
101            return "";
102        
103        // Get kth permutation for the left half.
104        string leftPermutation = kthPermutationForMultiset(leftCount, leftSize, k);
105        string rightPermutation = leftPermutation;
106        reverse(rightPermutation.begin(), rightPermutation.end());
107        return leftPermutation + mid + rightPermutation;
108    }
109};
110