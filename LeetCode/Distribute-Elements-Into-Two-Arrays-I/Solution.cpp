1class Solution {
2public:
3    vector<int> resultArray(vector<int>& nums) {
4        vector<int> a1, a2;
5        int n = nums.size();
6        a1.push_back(nums[0]);
7        a2.push_back(nums[1]);
8
9        for(int i=2; i<n; i++){
10            if(a1.back()>a2.back()){
11                a1.push_back(nums[i]);
12            }else{
13                a2.push_back(nums[i]);
14            }
15        }
16
17        for(int el: a2){
18            a1.push_back(el);
19        }
20
21        return a1;
22
23    }
24};