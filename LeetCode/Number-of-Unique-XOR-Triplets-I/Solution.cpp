1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int n = nums.size();
5        if(n == 1) return 1;
6        if(n == 2) return 2;
7        int mx = log2(n) + 1;
8
9        return (1<<mx);
10    }
11};