1struct node{
2    int t;
3    int b;
4    int l;
5    int r;
6    int area;
7    node(int x1, int y1, int x2, int y2){
8        t = y2;
9        b = y1;
10        l = x1;
11        r = x2;
12        area = (t-b)*(r-l);
13    }
14};
15
16class Solution {
17public:
18    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
19        node a = node(ax1, ay1, ax2, ay2);
20        node b = node(bx1, by1, bx2, by2);
21
22        if(a.b>=b.t || b.b>=a.t || a.r<=b.l || b.r<=a.l) return a.area + b.area;
23
24        int v = 0;
25
26        if(b.l>=a.l && b.r<=a.r){
27            v = b.r-b.l;
28        }else if(a.l>=b.l && a.r<=b.r){
29            v = a.r-a.l;
30        }else if(a.r>=b.l && a.r<=b.r){
31            v = (a.r-b.l);
32        }else if(b.r>=a.l && b.r<=a.r){
33            v = (b.r-a.l);
34        }
35
36        int h = 0;
37
38        if(b.t<=a.t && b.b>=a.b){
39            h = b.t-b.b;
40        }else if(a.t<=b.t && a.b>=b.b){
41            h = a.t-a.b;
42        }else if(a.b<=b.t && b.t<=a.t){
43            h = (b.t - a.b);
44        }else if(b.b<=a.t && a.t<=b.t){
45            h = (a.t-b.b);
46        }
47
48        return a.area + b.area - (h*v);
49    }
50};