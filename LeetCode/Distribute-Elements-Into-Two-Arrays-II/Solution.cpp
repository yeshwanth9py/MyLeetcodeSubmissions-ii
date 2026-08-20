1#include<bits/stdc++.h>
2using namespace std;
3
4#include<ext/pb_ds/assoc_container.hpp>
5#include<ext/pb_ds/tree_policy.hpp>
6
7using namespace __gnu_pbds;
8
9template<class T>
10using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
11
12
13class Solution {
14public:
15    vector<int> resultArray(vector<int>& nums) {
16        ordered_set<pair<int, int>> os1, os2;
17        os1.insert(make_pair(nums[0], 0));
18        os2.insert(make_pair(nums[1], 1));
19
20        vector<int> a1, a2;
21        a1.push_back(nums[0]);
22        a2.push_back(nums[1]);
23
24        int n = nums.size();
25
26        for(int i=2; i<n; i++){
27            int nog1 = os1.size() - os1.order_of_key({nums[i], 1e9});
28            int nog2 = os2.size() - os2.order_of_key({nums[i], 1e9});
29            if(nog1>nog2){
30                a1.push_back(nums[i]);
31                os1.insert({nums[i], i});
32            }else if(nog1<nog2){
33                a2.push_back(nums[i]);
34                os2.insert({nums[i], i});
35            }else if(a1.size()<=a2.size()){
36                a1.push_back(nums[i]);
37                os1.insert({nums[i], i});
38            }else{
39                a2.push_back(nums[i]);
40                os2.insert({nums[i], i});
41            }
42        }
43
44        for(int el: a2){
45            a1.push_back(el);
46        }
47
48        return a1;
49
50    }
51};
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67