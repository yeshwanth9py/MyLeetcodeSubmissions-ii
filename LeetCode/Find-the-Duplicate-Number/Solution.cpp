1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int sl = nums[0];
5        int fs = nums[0];
6        sl = nums[sl];
7        fs = nums[nums[fs]];
8        while(sl!=fs){
9            sl = nums[sl];
10            fs = nums[nums[fs]];
11        }
12        sl = nums[0];
13        while(sl!=fs){
14            sl = nums[sl];
15            fs = nums[fs];
16        }
17
18        return sl;
19    }
20};