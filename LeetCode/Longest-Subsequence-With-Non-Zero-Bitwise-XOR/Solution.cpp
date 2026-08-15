1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int x = 0;
5        int n = nums.size();
6        int noz = 0;
7        for(int el: nums){
8            if(el>0){
9                x ^= el;
10                noz++;
11            }
12        }
13
14        if(x != 0) return n;
15
16        if(noz>0) return n-1;
17        return 0;
18    }
19};