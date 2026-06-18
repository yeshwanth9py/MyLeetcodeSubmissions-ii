1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        double hd = ((60*(hour%12) + minutes)/720.00) * 360.00;
5        // cout<<hd<<" ";
6
7        double md = (minutes/60.0)*360.0;
8        return min(abs(hd-md), 360.00-abs(hd-md));
9    }
10};