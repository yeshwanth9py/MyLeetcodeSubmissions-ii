1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        vector<int> brr = arr;
5        sort(arr.begin(), arr.end());
6        int n = arr.size();
7        if(n == 0) return {};
8        int rnk = 1;
9        unordered_map<int, int> ump;
10        ump[arr[0]] = rnk;
11        rnk++;
12        for(int i=1; i<n; i++){
13            if(arr[i] != arr[i-1]){
14                ump[arr[i]] = rnk;
15                rnk++;
16            }
17        }
18
19        vector<int> ans;
20        for(int el: brr){
21            ans.push_back(ump[el]);
22        }
23
24        return ans;
25    }
26};