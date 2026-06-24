1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int n = nums.size();
5        int mxl = 0;
6        for(int i=0; i<n-1; i++){
7            mxl = max(mxl, i+nums[i]);
8            if(mxl == i) return 0;
9        }
10        return 1;
11    }
12};