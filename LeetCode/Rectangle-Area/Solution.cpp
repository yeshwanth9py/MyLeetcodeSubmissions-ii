1class Solution {
2public:
3    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
4        int area = (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1);
5        int left = max(bx1, ax1);
6        int right = min(bx2, ax2);
7        int top = min(ay2, by2);
8        int bot = max(ay1, by1);
9        if(left<right && bot<top){
10            area -= (right-left)*(top-bot);
11        }
12
13        return area;
14    }
15};