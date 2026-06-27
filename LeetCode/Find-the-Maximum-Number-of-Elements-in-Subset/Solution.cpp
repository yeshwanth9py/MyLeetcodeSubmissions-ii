1class Solution {
2public:
3    long long maximumLength(vector<int>& arr) {
4        unordered_map<long long, long long> vis;
5        sort(arr.begin(), arr.end());
6
7        unordered_map<long long, long long> ump;
8        for(long long el: arr){
9            ump[el]++;
10        }
11        long long n = arr.size();
12        long long maxl = 1;
13
14        for(long long i=0; i<n; i++){
15            long long cur = arr[i];
16            if(vis[cur]) continue;
17            cout<<cur<<" ";
18            long long cl = 0;
19            long long x = cur;
20            if(x == 1){
21                long long f = ump[x];
22                if(f%2 == 1){
23                    maxl = max(maxl, f);
24                }else{
25                    maxl = max(maxl, f-1);
26                }
27                vis[x] = 1;
28                continue;
29            }
30            while(1){
31                if(ump[cur] >= 2){
32                    cl+=2;
33                    vis[cur] = 1;
34                    cur = cur*cur;
35                }else if(ump[cur] == 1){
36                    cl+=1;
37                    vis[cur] = 1;
38                    maxl = max(maxl, cl);
39                    // cout<<maxl<<endl;
40                    break;
41                }else{
42                    maxl = max(maxl, cl-1);
43                    cout<<maxl<<endl;
44                    break;
45                }
46            }
47        }
48
49        return maxl;
50    }
51};