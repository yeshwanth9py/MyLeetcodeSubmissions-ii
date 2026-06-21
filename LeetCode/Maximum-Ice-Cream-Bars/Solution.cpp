1class Solution {
2public:
3    int maxIceCream(vector<int>& arr, int c) {
4        map<int, int> mp;
5        for(int el: arr){
6            mp[el]++;
7        }
8
9        int tot = 0;
10        for(auto el: mp){
11            if(el.first>c) break;
12            int cant = min(el.second, c/el.first);
13            tot += cant;
14            c -= cant*el.first;
15        }
16
17        return tot;
18    }
19};