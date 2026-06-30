1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int n = s.length();
5        int head = -1;
6        int tail = 0;
7
8        int a = 0;
9        int b = 0;
10        int c = 0;
11
12        int tot = 0;
13
14        while(tail<n){
15            while(head+1<n && (a==0 || b==0 || c==0)){
16                head++;
17                if(s[head] == 'a'){
18                    a++;
19                }else if(s[head] == 'b'){
20                    b++;
21                }else{
22                    c++;
23                }
24            }
25            if(a>0 && b>0 && c>0){
26                tot += n-head;
27            }
28
29            if(tail>head){
30                tail++;
31                head = tail-1;
32            }else{
33                if(s[tail] == 'a'){
34                    a--;
35                }else if(s[tail] == 'b'){
36                    b--;
37                }else{
38                    c--;
39                }
40                tail++;
41            }
42
43        }
44
45        return tot;
46    }
47};