1class Solution {
2public:
3    int removeCoveredIntervals(vector<vector<int>>& arr) {
4        int n = arr.size();
5        sort(arr.begin(), arr.end(), [&](vector<int> &a1, vector<int> &a2){
6            if(a1[0] != a2[0]) return a1[0]<a2[0];
7            return a1[1]>a2[1];
8        });
9
10        int i=0;
11        int cnt = 0;
12        while(i<n){
13            int j = i;
14            int st = arr[i][0];
15            int en = arr[i][1];
16            while(j+1<n && arr[j+1][1]<=en){
17                j++;
18            }
19            cnt++;
20            i = j+1;
21        }
22
23        return cnt;
24    }
25};