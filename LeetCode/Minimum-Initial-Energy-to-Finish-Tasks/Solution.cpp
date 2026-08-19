1class Solution {
2public:
3    int minimumEffort(vector<vector<int>>& arr) {
4        int n = arr.size();
5        sort(arr.begin(), arr.end(), [&](vector<int> &a1, vector<int> &a2){
6            return max(a1[1], a1[0]+a2[1]) < max(a2[1], a2[0]+a1[1]);
7        });
8
9        auto check = [&](int md){
10            int tot = md;
11            for(int i=0; i<arr.size(); i++){
12                if(arr[i][1]<=tot){
13                    tot -= arr[i][0];
14                }else{
15                    return 0;
16                }
17            }
18
19            return 1;
20        };
21
22        int lo = 0;
23        int hi = 1e9;
24        int ans = -1;
25
26        while(lo<=hi){
27            int mid = (lo+hi)/2;
28            if(check(mid)){
29                ans = mid;
30                hi = mid-1;
31            }else{
32                lo = mid+1;
33            }
34        }
35
36        while(1){
37            if(check(ans-1)){
38                ans = ans - 1;
39            }else{
40                break;
41            }
42        }
43
44        return ans;
45
46
47
48    }
49};