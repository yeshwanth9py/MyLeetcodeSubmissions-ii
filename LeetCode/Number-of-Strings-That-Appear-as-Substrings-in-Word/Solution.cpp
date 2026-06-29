1class Solution {
2public:
3    bool compare(string s1, string s2){
4        string s = s1 + "#" + s2;
5        int n = s.size();
6        vector<int> kmp(n+1, -1);
7        int i=0;
8        int j=-1;
9        while(i<n){
10            while(j!=-1 && s[i] != s[j]){
11                j = kmp[j];
12            }
13            i++;
14            j++;
15            kmp[i] = j;
16        }
17        for(int i=s1.size(); i<=n; i++){
18            if(kmp[i] == s1.size()) return 1;
19        }
20        return 0;
21    }
22
23    int numOfStrings(vector<string>& pat, string w) {
24        int cnt = 0;
25        for(string s: pat){
26            cnt += compare(s, w);
27        }
28        return cnt;
29    }
30};