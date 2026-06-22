1class Solution {
2public:
3    int searchInsert(vector<int>& arr, int target) {
4        int n = arr.size();
5        int lo = 0;
6        int hi = n-1;
7        int ans = n;
8        while(lo<=hi){
9            int mid = (lo+hi)/2;
10            if(arr[mid]>=target){
11                ans = mid;
12                hi = mid-1;
13            }else{
14                lo = mid+1;
15            }
16        }
17        return ans;
18    }
19};