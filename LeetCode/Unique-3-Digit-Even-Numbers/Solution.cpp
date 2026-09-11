1class Solution {
2public:
3    map<string, int> mp;
4    void rec(int ind, unordered_map<int, int> &ump, string &s){
5        if(ind == 3){
6            mp[s]++;
7            return;
8        }
9        for(auto el: ump){
10            if(el.second <= 0) continue;
11            if(ind == 0 && el.first != 0){
12                s += char(el.first+'0');
13                ump[el.first]--;
14                rec(ind+1, ump, s);
15                s.pop_back();
16                ump[el.first]++;
17            }else if(ind == 2 && el.first%2 == 0){
18                s += char(el.first+'0');
19                ump[el.first]--;
20                rec(ind+1, ump, s);
21                s.pop_back();
22                ump[el.first]++;
23            }else if(ind == 1){
24                s += char(el.first+'0');
25                ump[el.first]--;
26                rec(ind+1, ump, s);
27                s.pop_back();
28                ump[el.first]++;
29            }
30        }
31    }
32
33    int totalNumbers(vector<int>& dig) {
34        unordered_map<int, int> ump;
35
36        for(int el: dig){
37           ump[el]++;
38        }
39        string s = "";
40        rec(0, ump, s);
41
42        return mp.size();
43    }
44};