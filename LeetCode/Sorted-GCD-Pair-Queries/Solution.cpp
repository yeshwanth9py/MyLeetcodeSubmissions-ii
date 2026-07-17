1class Solution {
2public:
3    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
4        int mx = *max_element(nums.begin(), nums.end());
5        int n = nums.size();
6
7        vector<int> freq(mx + 1, 0);
8
9        for (int ek : nums) {
10            freq[ek]++;
11        }
12
13        vector<long long> allgcd(mx + 1, 0); // changed to long long
14
15        for (int i = 1; i <= mx; i++) {
16            for (int j = i; j <= mx; j = j + i) { // changed 2*i to i
17                allgcd[i] += freq[j];
18            }
19
20            long long cnt = allgcd[i];
21            allgcd[i] = (cnt * (cnt - 1)) / 2;
22        }
23
24        vector<long long> exact(mx + 1, 0); // changed to long long
25
26        for (int i = mx; i >= 1; i--) {
27            exact[i] = allgcd[i];
28
29            for (int j = 2 * i; j <= mx; j = j + i) {
30                exact[i] -= exact[j];
31            }
32        }
33
34        vector<long long> pref(mx + 1, 0); // changed to long long
35
36        pref[1] = exact[1];
37
38        for (int i = 2; i <= mx; i++) {
39            pref[i] = pref[i - 1] + exact[i];
40        }
41
42        vector<int> ans;
43
44        for (auto q : queries) {
45            auto it = upper_bound(pref.begin(), pref.end(), q);
46
47            // Do not decrement.
48            int ind = it - pref.begin();
49
50            ans.push_back(ind);
51        }
52
53        return ans;
54    }
55};