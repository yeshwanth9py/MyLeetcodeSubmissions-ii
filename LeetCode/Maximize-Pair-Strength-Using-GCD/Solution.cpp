1class Solution {
2public:
3    long long maxPairStrength(vector<int>& nums) {
4        long long n = nums.size();
5        long long ans = -1e9;
6        for(long long i=0; i<n; i++){
7            for(long long j=i+1; j<n; j++){
8                long long g = __gcd(nums[i], nums[j]);
9                g = g*g;
10                long long cur = (1LL*nums[i]*nums[j])/g;
11                ans = max(ans, cur);
12            }
13        }
14
15        return ans;
16    }
17};