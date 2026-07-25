1class Solution {
2public:
3    int maxProduct(int n) {
4        string s = to_string(n);
5        sort(s.rbegin(), s.rend());
6        return (s[0]-'0')*(s[1]-'0');
7    }
8};