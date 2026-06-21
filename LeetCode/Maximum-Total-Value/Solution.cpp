1class Solution {
2public:
3    const long long mod = 1e9+7;
4    long long maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
5        long long lo = 0;
6        long long hi = *(max_element(value.begin(), value.end()));
7        long long ans = 0;
8        auto check = [&](long long mid){
9            long long tiki = 0;
10            for(long long i=0; i<value.size(); i++){
11                if(value[i]<mid) continue;
12                long long take = (value[i] - mid)/decay[i];
13                take++;
14                tiki += take;
15                if(tiki>=m) return 1;
16            }
17            return 0;
18        };
19
20        while(lo<=hi){
21            long long mid = (lo+hi)/2;
22            if(check(mid)){
23                ans = mid;
24                lo = mid+1;
25            }else{
26                hi = mid-1;
27            }
28        }
29
30        long long rem = m;
31        long long prize = 0;
32        for(long long i=0; i<value.size(); i++){
33            if(value[i]<=ans) continue;
34            long long x = ((value[i]-(ans+1))/decay[i]) + 1;
35            x = min(x, rem);
36            long long cur = (1LL*value[i]*x) - 1LL*decay[i]*(x*(x-1))/2;
37            prize += cur;
38            prize = (prize%mod + mod)%mod;
39            rem -= x;
40        }
41
42        if(rem>0){
43            prize += 1LL*(rem)*ans;
44            prize = (prize%mod + mod)%mod;
45        }
46
47        return prize;
48    }
49};