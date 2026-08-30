1class Solution {
2public:
3    int n;
4    vector<int> arr;
5    int dp[101][5010];
6    int rec(int ind, int remsum){
7        if(remsum<0) return 1e9;
8        if(remsum==0){
9            return 0;
10        }
11        
12        if(ind == n){
13            return 1e9;
14        }
15        if(dp[ind][remsum] != -1) return dp[ind][remsum];
16        
17        int mul = 0;
18        int div = 0;
19        int cur = arr[ind];
20        int ans = rec(ind+1, remsum);
21
22        for(int div=0; div<=10; div++){
23            int dcur = cur;
24            mul = 0;
25            while(dcur<=remsum){
26                ans = min(ans, div + mul + rec(ind+1, remsum-dcur));
27                mul++;
28                dcur = dcur*2;
29            }
30            cur = cur/2;
31            if(cur == 0) break;
32        }
33
34        return dp[ind][remsum] = ans;
35    }
36    
37    int minOperations(vector<int>& nums, int sum) {
38        n = nums.size();
39        arr = nums;
40        memset(dp, -1, sizeof(dp));
41        int ans = rec(0, sum);
42        if(ans>=1e8) return -1;
43        return ans;
44    }
45    
46};