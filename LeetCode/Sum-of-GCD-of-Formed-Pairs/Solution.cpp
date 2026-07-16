1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> prefg(n, 0);
6        int mx = 0;
7        for(int i=0; i<n; i++){
8            mx = max(mx, nums[i]);
9            prefg[i] = __gcd(mx, nums[i]);
10        }
11
12        sort(prefg.begin(), prefg.end());
13
14        int i=0; 
15        int j=n-1;
16        long long ans = 0;
17        while(i<j){
18            int g = __gcd(prefg[i], prefg[j]);
19            ans += g;
20            i++;
21            j--;
22        }
23
24        return ans;
25    }
26};