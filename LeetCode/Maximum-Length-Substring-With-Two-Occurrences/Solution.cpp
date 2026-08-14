1class Solution {
2public:
3    int maximumLengthSubstring(string s) {
4        int n = s.size();
5        int i = 0;
6        int j = -1;
7        unordered_map<int, int> ump;
8        int ans = 0;
9
10        while(i<n){
11            while(j+1<n && ump[s[j+1]-'a']+1<=2){
12                j++;
13                ump[s[j]-'a']++;
14            }
15
16            if(j-i+1>0){
17                ans = max(ans, j-i+1);
18            }
19
20            if(i>j){
21                i++;
22                j=i-1;
23            }else{
24                ump[s[i]-'a']--;
25                i++;
26            }
27        }
28
29        return ans;
30    }
31};