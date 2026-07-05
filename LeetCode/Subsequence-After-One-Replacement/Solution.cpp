1class Solution {
2public:
3    bool canMakeSubsequence(string s, string t) {
4        if(s.size()>t.size()) return 0;
5        vector<int> pref(s.size(), 1e8);
6        int mc = 0;
7        for(int i=0; i<t.size(); i++){
8            if(t[i] == s[mc]){
9                pref[mc] = i;
10                mc++;
11                if(mc>=s.size()) break;
12            }
13        }
14        // for(int i=0; i<s.size(); i++){
15        //     cout<<pref[i]<<" ";
16        // }
17        // cout<<endl;
18        if(pref[s.size()-1]<1e8) return 1;
19        // cout<<"i"<<"\n";
20
21        mc = s.size()-1;
22        vector<int> suf(mc+1, -1);
23        for(int i=t.size()-1; i>=0; i--){
24            if(t[i] == s[mc]){
25                suf[mc] = i;
26                mc--;
27                if(mc<0) break;
28            }
29        }
30
31        if(suf[0] > -1) return 1;
32        // cout<<"i"<<"\n";
33
34        // for(int i=0; i<s.size(); i++){
35        //     cout<<suf[i]<<" ";
36        // }
37        // cout<<endl;
38
39        for(int i=0; i<s.size(); i++){
40            // cout<<(i-1>=0?pref[i-1]:0)<<" "<<(i+1<s.size()?suf[i+1]:(int) t.size()-1)<<", ";
41            if((i-1>=0?pref[i-1]:-1)<(i+1<s.size()?suf[i+1]:(int) t.size()) - 1) return 1;
42            cout<<"i"<<"\n";
43        }
44
45        return 0;
46    }
47};
48
49
50