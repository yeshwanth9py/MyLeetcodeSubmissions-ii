1class Solution {
2public:
3    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
4        long long n = nums.size();
5        long long mx = *(max_element(nums.begin(), nums.end()));
6        vector<long long> futg(mx+1, 0);
7
8        unordered_map<long long, long long> freq;
9        for(long long el: nums){
10            freq[el]++;
11        }
12
13        for(long long i=1; i<=mx; i++){
14            futg[i] = 0;
15            for(long long j=i; j<=mx; j=j+i){
16                futg[i] += freq[j];
17            }
18            futg[i] = (futg[i]*(futg[i]-1))/2;
19        }
20
21        vector<long long> exactg(mx+1, 0);
22        for(long long i=mx; i>=1; i--){
23            exactg[i] = futg[i];
24            for(long long j=2*i; j<=mx; j+=i){
25                exactg[i] -= exactg[j];
26            }
27        }
28
29        // cout<<exactg[1]<<" ";
30        for(long long i=2; i<=mx; i++){
31            // cout<<exactg[i]<<" ";
32            exactg[i] += exactg[i-1];
33        }
34
35        // cout<<endl;
36
37        vector<int> ans;
38        for(auto q: queries){
39            q++;
40            long long ind = lower_bound(exactg.begin(), exactg.end(), q)-exactg.begin();
41            if(ind == 0) ind = 1;
42            ans.push_back(ind);
43        }
44
45        return ans;
46    }
47};