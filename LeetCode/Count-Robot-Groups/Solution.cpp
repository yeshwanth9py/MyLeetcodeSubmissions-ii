1class Solution {
2public:
3    int countGroups(vector<int>& pos, vector<int>& spd, int dist) {
4        int n = pos.size();
5        int cnt = 1;
6        int minsp = spd[n-1];
7        for(int i=n-2; i>=0; i--){
8            if(spd[i]>minsp || pos[i+1]-pos[i]<=dist){
9                continue;
10            }else{
11                minsp = spd[i];
12                cnt++;
13            }
14        }
15
16        return cnt;
17    }
18};