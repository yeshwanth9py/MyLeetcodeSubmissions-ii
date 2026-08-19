1class Solution {
2public:
3    int minimumEffort(vector<vector<int>>& arr) {
4        sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b){
5            return max(a[0]+b[1], a[1]) < max(b[0]+a[1], b[1]);
6        });
7
8        int sm = 0;
9        for(int i=0; i<arr.size(); i++){
10            sm += arr[i][0];
11        }
12
13        if(arr[0][1]>sm){
14            sm = arr[0][1];
15        }
16
17        int act = sm;
18        for(int i=0; i<arr.size(); i++){
19            if(sm>=arr[i][1]){
20                sm -= arr[i][0];
21            }else{
22                act += (arr[i][1]-sm);
23                sm = arr[i][1] - arr[i][0];
24            }
25        }
26        // if(sm == 0){
27        //     sm++;
28        // }
29
30        return act;
31    }
32};