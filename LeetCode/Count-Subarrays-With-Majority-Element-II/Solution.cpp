1#include<bits/stdc++.h>
2#include<ext/pb_ds/assoc_container.hpp>
3#include<ext/pb_ds/tree_policy.hpp>
4
5using namespace __gnu_pbds;
6
7template <class T>
8
9using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
10
11class Solution {
12public:
13    long long countMajoritySubarrays(vector<int>& nums, int tar) {
14        ordered_set<pair<int, int>> os;
15        int n = nums.size();
16        vector<int> arr(n, 0);
17        for(int i=0; i<n; i++){
18            if(nums[i] == tar){
19                arr[i] = 1;
20            }else{
21                arr[i] = -1;
22            }
23        }
24
25        long long cs = 0;
26        os.insert({0, -1});
27        long long ans = 0;
28        for(int i=0; i<n; i++){
29            cs += arr[i];
30            // cs-1 >= x
31            int nsm = os.order_of_key({cs-1, 1e9});
32            // cout<<cs<<" "<<nsm<<endl;
33            ans += nsm;
34            os.insert({cs, i});
35        }
36        
37        return ans;
38    }
39};