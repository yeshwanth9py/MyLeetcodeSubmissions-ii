1class Solution {
2public:
3    int secondsBetweenTimes(string st, string et) {
4        int hr = stoi(st.substr(0, 2));
5        int min = stoi(st.substr(3, 2));
6        int sec = stoi(st.substr(6, 2));
7        sec += (min*60)  + (hr*3600);
8
9        hr = stoi(et.substr(0, 2));
10        min = stoi(et.substr(3, 2));
11        int sec2 = stoi(et.substr(6, 2));
12        sec2 += (min*60)  + (hr*3600);
13
14        return abs(sec2-sec);
15    }
16};