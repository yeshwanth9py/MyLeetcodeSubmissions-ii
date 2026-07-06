1class Solution {
2public:
3    vector<long long> spf;
4    const long long mod = 1e9+7;
5    unordered_map<long long, vector<long long>> store;
6    void pre(){
7        spf.resize(1e6+10, 0);
8        for(long long i=2; i<1e6+10; i++){
9            spf[i] = i;
10        }
11
12        for(long long i=2; i<1e6+10; i++){
13            if(spf[i] == i){
14                for(long long j=i*i; j<1e6+10; j+=i){
15                    if(spf[j] == j) spf[j] = i;
16                }
17            }
18        }
19    }
20
21    vector<long long> getprimes(long long num){
22        if(store.find(num) != store.end()) return store[num];
23        vector<long long> all;
24        int dnum = num;
25        for(int i=2; i*i<=num; i++){
26            if(num%i == 0){
27                while(num%i == 0){
28                    num = num/i;
29                }
30                all.push_back(i);
31            }
32        }
33        if(num>1){
34            all.push_back(num);
35        }
36        return store[dnum] = all;
37    }
38
39    long long divisibleGame(vector<int>& nums) {
40        long long n = nums.size();
41        // pre();
42        long long mxs = -1;
43        long long mxp = 2;
44
45        for(long long i=0; i<n; i++){
46            unordered_map<long long, long long> ump;
47            long long tot = 0;
48            for(long long j=i; j<n; j++){
49                tot += nums[j];
50                vector<long long> allprimes = getprimes(nums[j]);
51                for(long long p: allprimes){
52                    ump[p] += nums[j];
53                    int curs = 2*ump[p] - tot; 
54                    if(curs>mxs || (curs == mxs && mxp>p)){
55                        mxs = curs;
56                        mxp = p;
57                    }
58                }
59            }
60        }
61
62        // cout<<mxs<<" "<<mxp;
63        return ((mxs*mxp)%mod + mod)%mod;
64    }
65};