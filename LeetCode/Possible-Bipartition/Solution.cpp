1class Solution {
2public:
3    vector<vector<int>> adjl;
4    vector<int> vis;
5    int dfs(int node, int col, int pp){
6        vis[node] = col;
7        for(int nei: adjl[node]){
8            if(vis[nei] == -1){
9                if(!dfs(nei, !col, node)){
10                    return 0;
11                }
12            }else if(vis[nei] == col){
13                return 0;
14            }
15        }
16        return 1;
17    }
18
19    bool possibleBipartition(int n, vector<vector<int>>& arr) {
20        adjl.assign(n, vector<int>());
21        vis.assign(n, -1);
22
23        for(auto el: arr){
24            int a = el[0];
25            int b = el[1];
26            a--;
27            b--;
28            adjl[a].push_back(b);
29            adjl[b].push_back(a);
30        }
31
32        for(int i=0; i<n; i++){
33            if(vis[i] == -1){
34                int cur = dfs(i, 1, -1);
35                if(!cur) return 0;
36            }
37        }
38
39        return 1;
40
41    }
42};