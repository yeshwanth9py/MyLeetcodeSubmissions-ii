1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int sm = 1e9;
5        int mp = -1e9;
6        for(int i=0; i<prices.size(); i++){
7            if(prices[i]>=sm){
8                mp = max(mp, prices[i]-sm);
9            }
10            sm = min(sm, prices[i]);
11        }
12
13        return ((mp<=0)?0:mp);
14    }
15};