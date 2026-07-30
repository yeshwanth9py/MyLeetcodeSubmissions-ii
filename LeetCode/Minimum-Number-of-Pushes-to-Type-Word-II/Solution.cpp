1class Solution {
2public:
3    int minimumPushes(string word) {
4        priority_queue<int, vector<int>, greater<int>> pq;
5        for(int i=2; i<=9; i++) pq.push(1);
6        priority_queue<int> pq2;
7        vector<int> all(26, 0);
8        for(char ch: word){
9            all[ch-'a']++;
10        }
11
12        for(int i=0; i<26; i++){
13            pq2.push({all[i]});
14        }
15
16        int ans = 0;
17        while(!pq2.empty()){
18            auto tel = pq2.top(); pq2.pop();
19            auto noty = pq.top(); pq.pop();
20            ans += tel*noty;
21            noty++;
22            pq.push(noty);
23        }
24
25        return ans;
26    }
27};