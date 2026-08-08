1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& arr) {
4        int n = arr.size();
5        //o(n) xor  o(1)
6
7        // nums = check(nums) mid => [0,0,0,0,1,1,1,1]
8        //even 1st occ ,
9
10        //1 1 2 3 3 4 4 8 8
11        //0 1 2 3 4 5 6 7 8
12
13        //ans = -1
14        // (0+8)/2 => 4 , ans = 
15
16        int lo = 0;
17        int hi = n-1;
18        int ans = -1;
19
20        auto check = [&](int mid){
21            if(mid%2 == 0){
22                if(mid+1<n && arr[mid] == arr[mid+1]) return 0;
23                return 1;
24            }else{
25                if(mid-1>=0 && arr[mid-1] == arr[mid]) return 0;
26                return 1;
27            }
28        };
29
30        while(lo<=hi){
31            int mid = (lo+hi)/2;
32            if(check(mid)){
33                ans = mid;
34                hi = mid-1;
35            }else{
36                lo = mid+1;
37            }
38        }
39
40        return arr[ans];
41    }
42};