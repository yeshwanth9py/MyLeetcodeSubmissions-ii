1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<int> minn(n, 1e9);
6        minn[n-1] = nums[n-1];
7        for(int i=n-2; i>=0; i--){
8            minn[i] = min(minn[i+1], nums[i]);
9        }
10
11        int mx = -1;
12        for(int i=0; i<n; i++){
13            mx = max(mx, nums[i]);
14            if(mx - minn[i] <= k) return i;
15        }
16
17        return -1;
18
19
20    }
21};