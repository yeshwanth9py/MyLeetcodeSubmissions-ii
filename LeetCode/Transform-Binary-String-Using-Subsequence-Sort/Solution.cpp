1class Solution {
2public:
3    vector<bool> transformStr(string s, vector<string>& strs) {
4        int noz = 0;
5        int noo = 0;
6        for(char ch: s){
7            if(ch == '0'){
8                noz++;
9            }else{
10                noo++;
11            }
12        }
13
14        vector<bool> ans;
15        for(auto el: strs){
16            int cur = 0;
17            for(char ch: el){
18                if(ch == '1'){
19                    cur++;
20                }
21            }
22            if(cur>noo){
23                ans.push_back(0);
24                continue;
25            }
26
27            int ro = noo-cur;
28            for(int i=el.size()-1; i>=0; i--){
29                if(el[i] == '?'){
30                    if(ro){
31                        el[i] = '1';
32                        ro--;
33                    }else{
34                        el[i] = '0';
35                    }
36                }
37            }
38            cur = 0;
39            for(int i=0; i<el.size(); i++){
40                if(s[i] == el[i]) continue;
41                if(s[i] == '1'){
42                    cur++;
43                }else{
44                    cur--;
45                    if(cur<0){
46                        break;
47                    }
48                }
49            }
50            if(cur == 0){
51                ans.push_back(1);
52            }else{
53                ans.push_back(0);
54            }
55        }
56
57        return ans;
58
59    }
60};