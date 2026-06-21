1class Solution {
2public:
3    int maxIceCream(vector<int>& arr, int c) {
4        sort(arr.begin(), arr.end());
5        int tot = 0;
6        for(int el: arr){
7            if(el>c) break;
8            c -= el;
9            tot++;
10        }
11        return tot;
12    }
13};