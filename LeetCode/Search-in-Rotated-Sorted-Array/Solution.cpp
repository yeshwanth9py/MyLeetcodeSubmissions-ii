1class Solution {
2public:
3    int search(vector<int>& arr, int tar) {
4        int n = arr.size();
5        int lo = 0;
6        int hi = n-1;
7        int pk = n-1;
8
9        while(lo<=hi){
10            int mid = (lo+hi)/2;
11            if(arr[mid]>arr[n-1]){
12                lo = mid+1;
13                pk = mid;
14            }else{
15                hi = mid-1;
16            }
17        }
18        if(arr[pk] == tar) return pk;
19
20        lo = 0;
21        hi = pk;
22        int ans = 0;
23        while(lo<=hi){
24            int mid = (lo+hi)/2;
25            if(arr[mid]<=tar){
26                ans = mid;
27                lo = mid+1;
28            }else{
29                hi = mid-1;
30            }
31        }
32
33        if(arr[ans] == tar) return ans;
34
35        lo = pk+1;
36        hi = n-1;
37        while(lo<=hi){
38            int mid = (lo+hi)/2;
39            if(arr[mid] <= tar){
40                ans = mid;
41                lo = mid+1;
42            }else{
43                hi = mid-1;
44            }
45        }
46
47        if(arr[ans] == tar) return ans;
48
49        return -1;
50    }
51};