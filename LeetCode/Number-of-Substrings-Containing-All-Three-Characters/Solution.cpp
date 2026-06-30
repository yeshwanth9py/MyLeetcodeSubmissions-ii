1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int n = s.size();
5        unordered_map<char, int> ump;
6
7        int i = 0;
8        int j = -1;
9        int ans = 0;
10
11        while(i<n){
12            while(j+1<n && (ump[0] == 0 || ump[1] == 0 || ump[2] == 0)){
13                j++;
14                ump[s[j]-'a']++;
15            }
16
17            if(j-i+1>0 && ump[0]>0 && ump[1]>0 && ump[2]>0){
18                // cout<<i<<" "<<j<<" "<<(n-j)<<endl;
19                ans += (n-j);
20            }
21
22            if(i>j){
23                i++;
24                j=i-1;
25                ump.clear();
26            }else{
27                ump[s[i]-'a']--;
28                i++;
29            }
30        }
31
32        return ans;
33
34    }
35};