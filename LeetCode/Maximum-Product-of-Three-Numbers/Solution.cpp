1class Solution {
2public:
3    int n;
4    // int rec(int ind, int noel){
5    //     if(ind == n){
6    //         if(noel == 3) return 1;
7    //         return -
8    //     }
9    // }
10    int maximumProduct(vector<int>& nums) {
11        n = nums.size();
12        sort(nums.begin(), nums.end());
13
14        int pa = nums[0]*nums[1]*nums[n-1];
15        int pb = nums[n-1]*nums[n-2]*nums[n-3];
16        
17        return max(pa, pb);
18    }
19};