1class Solution {
2public:
3    int firstStableIndex(vector<int>& arr, int k) {
4        int n = arr.size();
5        int si = -1;
6        int mx = 1e9;
7        vector<int> minn(n, -1);
8        for(int i=n-1; i>=0; i--){
9            mx = min(mx, arr[i]);
10            minn[i] = mx;
11        }
12
13        mx = -1;
14        for(int i=0; i<n; i++){
15            mx = max(mx, arr[i]);
16            if((mx - minn[i])<=k){
17                return i;
18            }
19        }
20        
21        return -1;
22    }
23};
24
25
26