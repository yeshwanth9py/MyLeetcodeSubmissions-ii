1class Solution {
2public:
3    bool checker(int md, vector<int> &nums){
4        int leq = 0;
5        for(int el: nums){
6            if(el<=md){
7                leq++;
8            }
9        }
10        return leq>md;
11    }
12
13    int findDuplicate(vector<int>& nums) {
14        int n = nums.size();
15        int lo = 1;
16        int hi = n;
17        int ans = n+1;
18        while(lo<=hi){
19            int mid = (lo+hi)/2;
20            if(checker(mid, nums)){
21                ans = mid;
22                hi = mid-1;
23            }else{
24                lo = mid+1;
25            }
26        }
27        return ans;
28    }
29};