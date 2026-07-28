1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        string f = "";
5        vector<int> ump(26, 0);
6
7        for(char ch: s){
8            ump[ch-'a']++;
9        }
10
11        char od = '-';
12
13        for(int i=0; i<26; i++){
14            if(ump[i]%2 == 1){
15                // if(od != '') return "";
16                od = char('a'+i);
17                ump[i]--;
18            }
19        }
20
21        for(int i=0; i<26; i++){
22            if(ump[i]>0){
23                int nod = ump[i]/2;
24                // cout<<string(nod, char('a'+i))<<" ";
25                f += string(nod, char('a'+i));
26            }
27        }
28
29
30        string sec = f;
31        reverse(sec.begin(), sec.end());
32
33        if(od!='-'){
34            f += od;
35        }
36
37        f = f + sec;
38
39        return f;
40    }
41};