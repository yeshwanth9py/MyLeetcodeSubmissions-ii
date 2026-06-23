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
12
13        sl = nums[0];
14        while(sl!=fs){
15            sl = nums[sl];
16            fs = nums[fs];
17        }
18
19        return sl;
20
21    }
22};