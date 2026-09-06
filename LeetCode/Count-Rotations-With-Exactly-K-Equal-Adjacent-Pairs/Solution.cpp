1class Solution {
2public:
3    int countRotations(string s, int k) {
4        deque<char> dq;
5        int cur = 0;
6        for(char ch: s){
7            if(dq.size()>0 && dq.back() == ch){
8                cur++;
9            }
10            dq.push_back(ch);
11        }
12
13        int ans = 0;
14        if(cur == k){
15            ans++;
16        }
17
18        for(int i=0; i<s.size()-1; i++){
19            char tp = dq.front(); dq.pop_front();
20            if(dq.size()>0 && tp == dq.front()){
21                cur--;
22            }
23            if(dq.size()>0 && dq.back() == tp){
24                cur++;
25            }
26            dq.push_back(tp);
27            if(cur == k){
28                ans++;
29            }
30        }
31
32        return ans;
33    }
34};