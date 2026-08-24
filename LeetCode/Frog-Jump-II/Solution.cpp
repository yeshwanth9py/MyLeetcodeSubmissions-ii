1class Solution {
2public:
3    int maxJump(vector<int>& arr) {
4        int n = arr.size();
5        int lo = 1;
6        int hi = arr.back();
7        int ans = arr.back();
8
9        auto check = [&](int mid){
10            vector<int> vis(n, 0);
11
12            //go forward
13            int i = 0;
14            int j = 0;
15            while(i<n-1){
16                while(j+1<n && arr[j+1]-arr[i]<=mid){
17                    j++;
18                }
19                if(j == i) return 0;
20                vis[j] = 1;
21                i = j;
22            }
23
24            //come backwards
25            int cur = n-1;
26            for(int i=n-2; i>=0; i--){
27                if(vis[i] == 0 && arr[cur]-arr[i]<=mid){
28                    cur = i;
29                }
30            }
31
32            if(cur == 0) return 1;
33            return 0;
34        };
35
36        while(lo<=hi){
37            int mid = (lo+hi)/2;
38            if(check(mid)){
39                ans = mid;
40                hi = mid-1;
41            }else{
42                lo = mid+1;
43            }
44        }
45
46        return ans;
47
48    }
49};