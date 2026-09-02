1class Solution {
2public:
3    vector<int> pow2;
4    void pre(){
5        long long cur = 1;
6        int cnt = 0;
7        while(cnt<=25){
8            pow2.push_back(cur);
9            cur = cur*2;
10            cnt++;
11        }
12    }
13
14    long long findnear(long long el){
15        auto it = upper_bound(pow2.begin(), pow2.end(), el);
16        it--;
17        return it-pow2.begin();
18    }
19
20    long long binpow(long long x, long long n){
21        if(n == 0) return 1;
22        long long ans = binpow(x, n/2);
23        // if(ans>=(1<<13)) return (1<<26);
24        ans = 1LL*ans*ans;
25        if(n&1){
26            ans = ans*x;
27        }
28        return ans;
29    }
30
31    vector<string> largestString(vector<int>& nums) {
32        pre();
33        vector<string> ans;
34
35        for(long long el: nums){
36            string s = "";
37            long long cur = el;
38
39            while(cur>0){
40                long long sz = findnear(cur);
41                s += char(97+sz);
42                cur -= binpow(2, sz);
43            }
44
45            ans.push_back(s);
46        }
47
48        return ans;
49    }                                         
50
51
52};
53
54