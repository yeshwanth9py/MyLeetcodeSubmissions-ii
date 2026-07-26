1class Solution {
2public:
3    long long dx[4] = {-1, 0, 0, 1};
4    long long dy[4] = {0, -1, 1, 0};
5    long long minCost(long long n, long long m, vector<vector<int>>& pen) {
6        vector<vector<vector<long long>>> dist(n, vector<vector<long long>>(m, vector<long long>(2, 1e18)));
7
8        dist[0][0][0] = 1;
9        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
10        pq.push({0, 0, 0, 0});
11        while(!pq.empty()){
12            auto tel = pq.top(); pq.pop();
13            long long curc = tel[0];
14            long long x = tel[1];
15            long long y = tel[2];
16            long long cdir = tel[3];
17            long long ndir = (tel[3]+1)%2;
18            for(long long j=0; j<4; j++){
19                long long nx = x+dx[j];
20                long long ny = y+dy[j];
21                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
22                long long cost = ((nx+1)*(ny+1));
23                if(ndir==1){
24                    if(j<=1){
25                        cost += pen[x][y];
26                    }
27                }else{
28                    if(j>1){
29                        cost += pen[x][y];
30                    }
31                }
32                if(dist[nx][ny][ndir] > dist[x][y][cdir]+cost){
33                    dist[nx][ny][ndir] = dist[x][y][cdir]+cost;
34                    pq.push({dist[nx][ny][ndir], nx, ny, ndir});
35                }
36            }
37            if(dist[x][y][ndir]>dist[x][y][cdir]+pen[x][y]){
38                dist[x][y][ndir] = dist[x][y][cdir]+pen[x][y];
39                pq.push({dist[x][y][ndir], x, y, ndir});
40            }
41        }
42
43        return min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
44
45    }
46};