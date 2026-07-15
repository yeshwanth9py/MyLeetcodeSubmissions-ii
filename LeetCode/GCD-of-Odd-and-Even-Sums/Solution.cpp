1class Solution {
2public:
3    int gcdOfOddEvenSums(int n) {
4        int os = n*n;
5        int tn = n+n;
6        int ts = (tn*(tn+1))/2;
7        int es = (ts - os);
8        // cout<<es<<" "<<os<<endl;
9        return __gcd(es, os);
10    }
11};