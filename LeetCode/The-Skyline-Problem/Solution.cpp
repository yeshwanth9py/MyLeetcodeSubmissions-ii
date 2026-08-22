1class Solution {
2public:
3    vector<vector<int>> getSkyline(vector<vector<int>>& arr) {
4        multiset<int> ms;
5        // ms.insert(0);
6
7        vector<vector<int>> sweep; // x, 1/2, ht
8        for(auto el: arr){
9            int x1 = el[0];
10            int x2 = el[1];
11            int ht = el[2];
12            sweep.push_back({x1, 1, ht});
13            sweep.push_back({x2, 2, ht});
14        }
15
16        sort(sweep.begin(), sweep.end(), [&](vector<int> &a, vector<int> &b){
17            if(a[0] != b[0]){
18                return a[0]<b[0];
19            }
20            if(a[1] != b[1]){
21                return a[1]<b[1];
22            }
23            
24           if(a[1] == 1){
25                return a[2]>b[2];
26           }
27           return a[2]<b[2];
28        });
29
30        vector<vector<int>> ans;
31
32        for(int i=0; i<sweep.size(); i++){
33            int x = sweep[i][0];
34            int typ = sweep[i][1];
35            int ht = sweep[i][2];
36
37            if(typ == 1){
38                if(ms.empty() || (*ms.rbegin())<ht){
39                    ans.push_back({x, ht});
40                }
41                ms.insert(ht);
42            }else{
43                ms.erase(ms.find(ht));
44                if(!ms.empty() && (*ms.rbegin())<ht){
45                    ans.push_back({x, (*ms.rbegin()) });
46                }else if(ms.empty()){
47                    ans.push_back({x, 0});
48                }
49            }
50        }
51
52        return ans;
53
54    }
55};