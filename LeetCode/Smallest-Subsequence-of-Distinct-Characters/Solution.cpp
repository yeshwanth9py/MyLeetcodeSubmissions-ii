1class Solution {
2public:
3    int need;
4    int n;
5    string smallestSubsequence(string s) {
6        unordered_map<char, int> ump;
7        n = s.size();
8        for(char ch: s){
9            ump[ch]++;
10        }
11
12        stack<char> st;
13        unordered_map<char, int> inst;
14        for(char ch: s){
15            while(!st.empty() && st.top()>ch && ump[st.top()]>0 && inst[ch] == 0){
16                inst[st.top()]--;
17                st.pop();
18            }
19            ump[ch]--;
20            if(inst[ch]==0){
21                st.push(ch);
22                inst[ch]++;
23            }
24        }
25
26        string ans = "";
27        while(!st.empty()){
28            ans += st.top(); st.pop();
29        }
30
31        reverse(ans.begin(), ans.end());
32        return ans;
33    }
34};