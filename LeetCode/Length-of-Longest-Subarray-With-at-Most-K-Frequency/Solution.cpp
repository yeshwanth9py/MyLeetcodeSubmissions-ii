1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4        int n = nums.size();
5        unordered_map<int, int> ump;
6        int i = 0;
7        int j = -1;
8        int ans = 0;
9        
10        while(i<n){
11            while(j+1<n && ump[nums[j+1]]+1<=k){
12                j++;
13                ump[nums[j]]++;
14            }
15            if(j-i+1>0){
16                ans = max(ans, j-i+1);
17            }
18            if(i>j){
19                i++;
20                j=i-1;
21            }else{
22                ump[nums[i]]--;
23                i++;
24            }
25        }
26
27        return ans;
28    }
29};