1class MyCalendarTwo {
2public:
3    vector<pair<int, int>> ones, twos;
4    MyCalendarTwo() {
5        ones.clear();
6        twos.clear();
7    }
8    
9    bool book(int st, int et) {
10        bool found = 0;
11        et = et-1;
12        for(auto [s, e]: twos){
13            if(et<s || e<st) continue;
14            return 0;
15        }
16
17        for(auto [s, e]: ones){
18            if(et<s || e<st) continue;
19            int f = max(st, s);
20            int l = min(e, et);
21            twos.push_back({f, l});
22        }
23
24        ones.push_back({st, et});
25        return 1;
26    }
27};
28
29/**
30 * Your MyCalendarTwo object will be instantiated and called as such:
31 * MyCalendarTwo* obj = new MyCalendarTwo();
32 * bool param_1 = obj->book(startTime,endTime);
33 */