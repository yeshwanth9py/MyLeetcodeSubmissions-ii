1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        unordered_map<char, int> fut;
5        string ans = "";
6        unordered_map<char, int> inst;
7        for(char ch: s){
8            fut[ch]++;
9        }
10        
11        for(char ch: s){
12            while(ans.size() > 0 && ans.back()>ch && fut[ans.back()]>0 && inst[ch]==0){
13                inst[ans.back()]--;
14                ans.pop_back();
15            }
16            fut[ch]--;
17            if(inst[ch] == 0){
18                ans.push_back(ch);
19                inst[ch] = 1;
20            }
21        }
22        return ans;
23    }
24};