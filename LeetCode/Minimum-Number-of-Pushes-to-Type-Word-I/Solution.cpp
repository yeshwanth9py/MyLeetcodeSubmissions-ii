1class Solution {
2public:
3    int minimumPushes(string word) {
4        priority_queue<int, vector<int>, greater<int>> pq;
5
6        for(int i=2; i<=9; i++) pq.push(1);
7
8        vector<int> alph(26, 0);
9
10        int ans = 0;
11        for(char ch: word){
12            if(alph[ch-'a'] == 0){
13                int tel = pq.top(); pq.pop();
14                alph[ch-'a'] = tel;
15                tel++;
16                pq.push(tel);
17            }
18            ans += alph[ch-'a'];
19        }
20
21        return ans;
22    }
23};