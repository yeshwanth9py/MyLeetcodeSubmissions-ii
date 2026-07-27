1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6        return (nums[n-1]-1)*(nums[n-2]-1);
7    }
8};