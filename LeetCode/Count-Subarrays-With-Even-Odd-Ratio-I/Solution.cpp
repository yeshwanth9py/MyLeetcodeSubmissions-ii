1class Solution {
2public:
3    int countRatioSubarrays(vector<int>& nums, int a, int b) {
4        int n = nums.size();
5        int ans = 0;
6        for(int l=0; l<n; l++){
7            int e = 0;
8            int o = 0;
9            for(int r=l; r<n; r++){
10                if(nums[r]%2 == 0){
11                    e++;
12                }else{
13                    o++;
14                }
15                if(o>0){
16                    if(e*b<=o*a){
17                        ans++;
18                    }
19                }
20            }
21        }
22
23
24        return ans;
25    }
26};