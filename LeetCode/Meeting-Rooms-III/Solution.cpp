1class Solution {
2public:
3    long long mostBooked(long long n, vector<vector<int>>& arr) {
4        priority_queue<long long, vector<long long>, greater<long long>> avail;  
5
6        for(long long i=0; i<n; i++){
7            avail.push(i);
8        }
9
10        unordered_map<long long, long long> usage;
11        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> inuse;  //{et, rm}
12        unordered_map<long long, long long> ump;
13
14        sort(arr.begin(), arr.end());
15
16        for(auto el: arr){
17            long long s = el[0];
18            long long e = el[1];
19
20            while(!inuse.empty() && inuse.top().first<=s){
21                auto [et, rm] = inuse.top(); inuse.pop();
22                avail.push(rm);
23            }
24
25            if(avail.size() == 0){
26                auto [et, rm] = inuse.top(); inuse.pop();
27                long long dura = e-s;
28                long long aet = et+dura;
29                inuse.push({aet, rm});
30                usage[rm]++;
31            }else{
32                auto tel = avail.top(); avail.pop();
33                inuse.push({e, tel});
34                usage[tel]++;
35            }
36        }
37
38        long long mxfr = 0;
39
40        for(long long i=0; i<n; i++){
41            if(usage[mxfr]<usage[i]){
42                mxfr = i;
43            }
44        }
45
46        return mxfr;
47    }
48};