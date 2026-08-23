1class Solution {
2public:
3    bool sumGame(string num) {
4        int l1 = 0;
5        int l2 = 0;
6        int r1 = 0;
7        int r2 = 0;
8        int n = num.size();
9
10        int totch = 0;
11        for(int i=0; i<n; i++){
12            if(i<n/2){
13                if(num[i] == '?'){
14                    l2+=9;
15                    totch++;
16                }else{
17                    l1 += (num[i]-'0');
18                    l2 += (num[i] - '0');
19                }
20            }else{
21                if(num[i] == '?'){
22                    r2+=9;
23                    totch++;
24                }else{
25                    r1 += (num[i]-'0');
26                    r2 += (num[i]-'0');
27                }
28            }
29        }
30
31        // Bob can only win if (2 * left_sum + 9 * left_questions) == (2 * right_sum + 9 * right_questions)
32        return l1 + l2 != r1 + r2;
33    }
34};