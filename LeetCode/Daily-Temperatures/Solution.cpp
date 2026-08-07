1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& arr) {
4        // vector<int> ans(n, 0);
5        // st = {{el, ind}} //montonic stack 
6        // i = n-1  -> 0
7        // st = {73}
8        // i = n-2  -> 0
9        // st = {76}
10        // i = n-3  -> j-i -> 1
11        // st = {{72, 5}, {76, 6}}
12        int n = arr.size();
13        
14        vector<int> ans(n, 0);
15        stack<pair<int, int>> st;
16        for(int i=n-1; i>=0; i--){
17            while(!st.empty() && st.top().first<=arr[i]){
18                st.pop();
19            }
20            if(!st.empty()){
21                auto [tv, j] = st.top(); 
22                ans[i] = j-i;
23            }
24            st.push({arr[i], i});
25        }
26
27        return ans;
28
29    }
30};