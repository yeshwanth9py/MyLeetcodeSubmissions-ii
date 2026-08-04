1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        vector<int> ext;
6
7        int lo = nums[0];
8        int hi = nums.back();
9        int n = nums.size();
10
11        int i = 0;
12        while(i<n){
13            if(nums[i] != lo){
14                ext.push_back(lo);
15                lo++;
16                continue;
17            }
18            i++;
19            lo++;
20        }
21
22        return ext;
23
24        
25    }
26};