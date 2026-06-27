1class Solution {
2public:
3    long long maximumLength(vector<int>& nums) {
4        //get the head in a chain approach
5        unordered_map<long long, long long> ump;
6        for(long long el: nums){
7            ump[el]++;
8        }
9        long long maxl = 1;
10
11        for(long long el: nums){
12            if(el == 1){
13                long long fl = ump[el];
14                if(fl%2 == 1){
15                    maxl = max(maxl, fl);
16                }else{
17                    maxl = max(maxl, fl-1);
18                }
19                continue;
20            }
21            long long sq = sqrt(el);
22            // if(sq*sq != el) continue;
23            if(sq*sq==el && ump[sq]>=2) continue;
24            long long cl = 0;
25            long long cur = el;
26            // cout<<cur<<" ";
27            while(1){
28                if(ump[cur]>=2){
29                    cl+=2;
30                    cur = cur*cur;
31                }else if(ump[cur] == 1){
32                    cl+=1;
33                    maxl = max(maxl, cl);
34                    cout<<cl<<endl;
35                    break;
36                }else{
37                    maxl = max(maxl, cl-1);
38                    cout<<cl<<endl;
39                    break;
40                }
41            }
42        }
43
44        return maxl;
45
46    }
47};