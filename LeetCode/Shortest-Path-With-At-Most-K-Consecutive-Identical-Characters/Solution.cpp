1class Solution {
2public:
3    vector<vector<pair<int, int>>> adjl;
4    vector<vector<int>> dist;
5    int shortestPath(int n, vector<vector<int>>& edges, string s, int k) {
6        adjl.resize(n, vector<pair<int, int>>());
7        dist.resize(n+2, vector<int>(k+2, 1e9));
8        for(auto edg: edges){
9            int u = edg[0];
10            int v = edg[1];
11            int wt = edg[2];
12            adjl[u].push_back({v, wt});
13        }
14        
15        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
16
17        pq.push({0, 0, s[0]-'a', 1});  //dist, node, lastch, repeat
18        dist[0][1] = 0;
19        
20        while(!pq.empty()){
21            auto tel = pq.top(); pq.pop();
22            int dis = tel[0];
23            int nod = tel[1];
24            int lc = tel[2];
25            int rep = tel[3];
26            if(dis != dist[nod][rep]) continue;
27            for(auto [nei, neiwt]: adjl[nod]){
28                int nlc = s[nei]-'a';
29                int nrep = 1;
30                if(nlc == lc){
31                    nrep += rep;
32                }
33                if(nrep>k) continue;
34                if(dist[nei][nrep]>dis+neiwt){
35                    dist[nei][nrep] = dis+neiwt;
36                    pq.push({dist[nei][nrep], nei, nlc, nrep});
37                }
38            }
39        }
40
41        int ans = 1e9;
42
43        for(int r=0; r<=k; r++){
44            ans = min(ans, dist[n-1][r]);
45        }
46        
47        if(ans == 1e9) return -1;
48        return ans;
49    }
50};