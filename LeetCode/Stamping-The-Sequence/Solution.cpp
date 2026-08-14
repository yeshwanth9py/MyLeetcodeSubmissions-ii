1class Solution {
2public:
3    vector<int> movesToStamp(string t, string s) {
4        int n = s.size();
5        int m = t.size();
6
7        unordered_map<int, set<int>> ump; //window -> chars
8        vector<vector<int>> graph(n, vector<int>());  //char ->windows
9
10        vector<int> vis(n, 0);
11
12        for(int i=0; i<=n-m; i++){
13            for(int j=0; j<m; j++){
14                if(s[i+j] != t[j]){
15                    ump[i].insert(i+j);
16                    graph[i+j].push_back(i);
17                }
18            }
19        }
20
21        queue<int> q;
22        for(int i=0; i<=n-m; i++){
23            if(ump[i].size() == 0){
24                //this widow is clear and have no controversies
25                q.push(i);
26            }
27        }
28
29        
30        // cout<<q.size()<<" ";
31        vector<int> ans;
32        while(!q.empty()){
33            auto tn = q.front(); q.pop();
34
35            ans.push_back(tn);
36            for(int j = 0; j<m; j++){
37                int pos = tn+j;
38                if(!vis[pos]){
39                    vis[pos] = 1;
40                    for(int w: graph[pos]){
41                        if(w == tn) continue;
42                        ump[w].erase(pos);
43                        if(ump[w].size() == 0){
44                            q.push(w);
45                        }
46                    }
47                }
48            }
49        }
50
51        for(int i=0; i<n; i++){
52            if(vis[i] == 0) return {};
53        }
54
55
56        reverse(ans.begin(), ans.end());
57
58        return ans;
59    }
60};
61
62
63