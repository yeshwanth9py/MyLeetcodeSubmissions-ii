1class Solution {
2public:
3    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
4        sort(arr.begin(), arr.end());
5        int cur = 0;
6        int i = 0;
7        int ans = 0;
8        while(i<arr.size()){
9            int st = arr[i][0]-1;
10            if(cur<st){
11                ans += 2*(st-cur);
12                cur = st;
13            }
14 
15            vector<int> temp(10, 0);
16            int j = i;
17            while(j<arr.size() && (arr[j][0]-1)==cur){
18                int ten = arr[j][1]-1;
19                temp[ten] = 1;
20                j++;
21            }
22
23            for(int k=0; k<10; k++){
24                temp[k] += (k-1>=0?temp[k-1]:0);
25            }
26            
27            if((temp[4] - temp[0] == 0) && (temp[8]-temp[4]) == 0){
28                ans += 2;
29            }else if((temp[4] - temp[0] == 0) || ((temp[8]-temp[4]) == 0) || (temp[6] - temp[2] == 0)){
30                ans += 1;
31            }
32
33            i = j;
34            cur++;
35        }
36
37        ans += 2*(n-cur);
38
39        return ans;
40
41    }
42};