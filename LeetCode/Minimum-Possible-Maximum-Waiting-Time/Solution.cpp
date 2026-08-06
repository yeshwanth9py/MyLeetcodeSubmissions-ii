1class Solution {
2public:
3    // 2500 * 2500 = 6250000
4    vector<int> dem;
5    int n;
6    pair<int, int> dp[51][21][21][51];
7    pair<int, int> rec(int ind, int av1, int av2, int dis1, int dis2){
8        if(ind == n){
9            return {0, 0}; //no of cars, wait time
10        }
11
12        if(dp[ind][av1][av2][dis1].first != -1) return dp[ind][av1][av2][dis1];
13
14        int wt = 1e9;
15        int carsu = 0;
16
17        if(dis1>=dem[ind]){
18            auto [retc, retwt] = rec(ind+1, dem[ind], max(0, av2-av1), dis1-dem[ind], dis2);
19            if(retwt>=1e8) retwt = -1;
20            retc++;
21            retwt = max(retwt, av1);
22            if(retc>carsu || ((retc == carsu) && retwt<wt)){
23                wt = retwt;
24                carsu = retc;
25            }
26        }
27
28        if(dis2>=dem[ind]){
29            auto [retc, retwt] = rec(ind+1, max(0, av1-av2), dem[ind], dis1, dis2-dem[ind]);
30            if(retwt>=1e8) retwt = -1;
31            retc++;
32            retwt = max(retwt, av2);
33            if(retc>carsu || ((retc == carsu) && retwt<wt)){
34                wt = retwt;
35                carsu = retc;
36            }
37        }
38
39        return dp[ind][av1][av2][dis1] = {carsu, wt};
40    }
41
42    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
43        dem = demand;
44        n = dem.size();
45        if(fuel[0]<dem[0] && fuel[1]<dem[0]) return -1;
46        memset(dp, -1, sizeof(dp));
47        auto [ansc, answt] = rec(0, 0, 0, fuel[0], fuel[1]);
48        // if(ans>=1e8) return -1;
49        return answt;
50    }
51};