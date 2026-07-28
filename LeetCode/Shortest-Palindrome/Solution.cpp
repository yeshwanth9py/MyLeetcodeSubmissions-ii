1class Solution {
2public:
3    int kmpp(string &s, int sta){
4        int n = s.size();
5        vector<int> kmp(n+1, 0);
6        int i = 0;
7        int j = -1;
8        kmp[i] = j;
9        while(i<n){
10            while(j!=-1 && s[i] != s[j]) j = kmp[j];
11            i++;
12            j++;
13            kmp[i] = j;
14        }
15
16        return kmp[n];
17    }
18
19    string shortestPalindrome(string s) {
20        int n = s.size();
21        if(n<=1) return s;
22
23        string dup = s;
24        string t = s;
25        reverse(t.begin(), t.end());
26        s = s + "#" + t;
27        int lcp = kmpp(s, n+1);
28        lcp = n-lcp;
29        string ex = "";
30        for(int i=dup.size()-1; i>=dup.size()-1-lcp+1; i--){
31            ex += dup[i];
32        }
33
34        ex = ex+dup;
35        return ex;
36    }
37};
38