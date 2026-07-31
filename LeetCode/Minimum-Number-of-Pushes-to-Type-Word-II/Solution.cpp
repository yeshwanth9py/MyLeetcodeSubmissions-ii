1class Solution {
2public:
3    int minimumPushes(string word) {
4        priority_queue<int, vector<int>, greater<int>> pq;
5        for(int i=2; i<=9; i++){
6            pq.push(1);
7        }
8        vector<int> alph(26, 0);
9        for(char ch: word){
10            alph[ch-'a']++;
11        }
12
13        sort(alph.rbegin(), alph.rend());
14        int ans = 0;
15        for(int i=0; i<26; i++){
16            auto tel = pq.top(); pq.pop();
17            ans += alph[i]*tel;
18            tel++;
19            pq.push(tel);
20        }
21
22        return ans;
23    }
24};