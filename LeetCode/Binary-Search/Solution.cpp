1class Solution {
2public:
3    int search(vector<int>& arr, int target) {
4        int n = arr.size();
5        int lo = 0;
6        int hi = n-1;
7        int ans = 0;
8        while(lo<=hi){
9            int mid = (lo+hi)/2;
10            if(arr[mid]<=target){
11                ans = mid;
12                lo = mid+1;
13            }else{
14                hi = mid-1;
15            }
16        }
17        return ((arr[ans] == target)?ans:-1);
18    }
19};