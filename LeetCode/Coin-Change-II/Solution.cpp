1class Solution {
2public:
3    vector<int> arr;
4    long long dp[301][5001];
5    int amt;
6
7    int rec(){
8        for(int ind=arr.size(); ind>=0; ind--){
9            for(int rem=0; rem<=amt; rem++){
10                if(ind == arr.size()){
11                    dp[ind][rem] = (rem==0);
12                    continue;
13                }
14
15                long long dontake = dp[ind+1][rem];
16                long long take = (rem-arr[ind]>=0 ? dp[ind][rem-arr[ind]] : 0);
17
18                if(dontake > INT_MAX - take)
19                    dp[ind][rem] = INT_MAX;
20                else
21                    dp[ind][rem] = dontake + take;
22            }
23        }
24        return dp[0][amt];
25    }
26
27    int change(int amount, vector<int>& coins) {
28        arr = coins;
29        amt = amount;
30        memset(dp, -1, sizeof(dp));
31        return rec();
32    }
33};