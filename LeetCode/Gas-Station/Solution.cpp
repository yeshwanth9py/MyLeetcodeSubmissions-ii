1class Solution {
2public:
3    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
4        int n = gas.size();
5        vector<int> dif(n, 0);
6        for(int i=0; i<n; i++){
7            dif[i] = gas[i]-cost[i];
8        }
9
10        vector<int> pref(n, 0);
11
12        int sti = 0;
13        int m = 0;
14
15        for(int i=0; i<n; i++){
16            pref[i] = dif[i];
17            if(i){
18                pref[i] += pref[i-1];
19            }
20
21            if(pref[i]<m){
22                m = pref[i];
23                sti = i+1;
24            }
25        }
26
27        if(pref[n-1]<0) return -1;
28
29        
30        for(int i=sti; i<n; i++){
31            int curf = pref[i] - m;
32            if(curf<0) return -1;
33        }
34
35        for(int i=0; i<sti; i++){
36            int curf = pref[n-1] - m + pref[i];
37            if(curf<0) return -1;
38        }
39
40        return sti;
41
42    }
43};