1class Solution {
2public:
3    int countGoodRotations(vector<int>& nums) {
4        deque<long long> dq1, dq2;
5        long long n = nums.size();
6        long long fh = 0;
7        long long sh = 0;
8
9        for(long long i=0; i<n; i++){
10            if(i<n/2){
11                fh += nums[i];
12                dq1.push_back(nums[i]);
13            }else{
14                sh += nums[i];   
15                dq2.push_back(nums[i]);
16            }
17        }
18
19
20
21        long long ans = 0;
22        if(fh>sh){
23            ans++;
24        }
25
26        for(long long i=0; i<n-1; i++){
27            long long f1 = dq1.front(); dq1.pop_front();
28            long long f2 = dq2.front(); dq2.pop_front();
29            fh -= f1;
30            fh += f2;
31            dq1.push_back(f2);
32            dq2.push_back(f1);
33            sh -= f2;
34            sh += f1;
35            if(fh>sh){
36                ans++;
37            }
38        }
39
40        return ans;
41
42    }
43};