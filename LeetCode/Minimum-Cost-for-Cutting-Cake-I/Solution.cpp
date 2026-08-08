1class Solution {
2public:
3    int minimumCost(int n, int m, vector<int>& harr, vector<int>& varr) {
4        int nov = 0;
5        int noh = 0;
6
7        priority_queue<vector<int>> pq;
8        for(int i=0; i<harr.size(); i++){
9            pq.push({harr[i], i, -1});
10        }
11
12        for(int i=0; i<varr.size(); i++){
13            pq.push({varr[i], i, 1});
14        }
15
16        int tc = 0;
17        while(!pq.empty()){
18            auto tel = pq.top(); pq.pop();
19            if(tel[2] == 1){
20                tc += tel[0]*(noh+1);
21                nov++;
22            }else{
23                tc += tel[0]*(nov+1);
24                noh++;
25            }
26        }
27
28        return tc;
29
30    }
31};