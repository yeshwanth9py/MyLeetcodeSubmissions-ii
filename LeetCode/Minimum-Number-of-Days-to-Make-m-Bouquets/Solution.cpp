1class Solution {
2public:
3    bool checker(int md, vector<int> &arr, int k, int m){
4        int n = arr.size();
5        int i=0;
6        int j=-1;
7        int cnt = 0;
8        while(i<n){
9            while(j+1<n && arr[j+1]<=md && j-i+1<k){
10                j++;
11            }
12            if(j-i+1==k){
13                cnt++;
14            }
15            if(i>j){
16                i++;
17                j=i-1;
18            }else{
19                i=j+1;
20            }
21        }
22
23        return cnt>=m;
24    }
25
26    int minDays(vector<int>& arr, int m, int k) {
27        int lo = 0;
28        int hi = *max_element(arr.begin(), arr.end());
29        int ans = -1;
30        while(lo<=hi){
31            int mid = (lo+hi)/2;
32            if(checker(mid, arr, k, m)){
33                ans = mid;
34                hi = mid-1;
35            }else{
36                lo = mid+1;
37            }
38        }
39
40        return ans;
41
42    }
43};