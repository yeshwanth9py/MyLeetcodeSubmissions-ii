1class Solution {
2public:
3    int minOperations(string s1, string s2) {
4        int n = s1.size();
5        int i=0;
6        int ways = 0;
7        while(i<n){
8            if(s1[i] == '0'){
9                if(s2[i] == '1'){
10                    ways++;
11                }
12            }else{
13                if(s2[i] == '1'){
14                    //
15                }else{
16                    if(i+1<n && s1[i+1] == '1' && s2[i+1] == '0'){
17                        ways += 1;
18                        i++;
19                    }else if(i-1>=0){
20                        ways+=2;
21                    }else if(i+1<n && s1[i+1] == '1' && s2[i+1] == '1'){
22                        ways += 2;
23                    }else if(i+1<n && s1[i+1] == '0' && s2[i+1] == '0'){
24                        ways += 2;
25                        i++;
26                    }else if(i+1<n && s1[i+1] == '0' && s2[i+1] == '1'){
27                        ways += 3;
28                        i++;
29                    }else if(i-1>=0){
30                        ways += 3;
31                        i++;
32                    }else{
33                        return -1;
34                    }
35                }
36            }
37            i++;
38        }
39
40        return ways;
41    }
42};