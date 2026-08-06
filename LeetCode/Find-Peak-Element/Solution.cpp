1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4        int n = nums.size();
5        if(n==1) return 0;
6        if(n == 2){
7            if(nums[0]>nums[1]) return 0;
8            return 1;
9        }
10
11        int lo = 0;
12        int hi = n-1;
13        int ans = 0;
14        while(lo<=hi){
15            int mid = (lo+hi)/2;
16            if(mid-1>=0 && nums[mid-1]>nums[mid]){
17                ans = mid-1;
18                hi = mid-1;
19            }else if(mid+1<n && nums[mid+1]>nums[mid]){
20                ans = mid+1;
21                lo = mid+1;
22            }else{
23                return mid;
24            }
25        }
26
27        return ans;
28    }
29};