1class Solution {
2public:
3    bool compare(string s1, string s2){
4        string s = s1 + "#" + s2;
5        int n = s.size();
6        vector<int> kmp(n+1, -1);
7        int i=0;
8        int j=-1;
9        while(i<n){
10            while(j != -1 && s[i]!=s[j]){
11                j = kmp[j];
12            }
13            j++;
14            i++;
15            kmp[i] = j;
16        }
17
18        for(int i=s1.size(); i<=n; i++){
19            if(kmp[i] == s1.size()) return 1;
20        }
21
22        return 0;
23    }
24
25    int numOfStrings(vector<string>& pat, string w) {
26        int cnt = 0;
27        for(string s: pat){
28            cnt += compare(s, w);
29        }
30        return cnt;
31    }
32};