1class MyCalendar {
2public:
3    vector<pair<int, int>> arr;
4    MyCalendar() {
5        arr.clear();
6    }
7    
8    bool book(int st, int et) {
9        for(auto [t1, t2]: arr){
10            if(et<=t1 || st>=t2){
11                continue;
12            }else{
13                return 0;
14            }
15        }
16        arr.push_back({st, et});
17        return 1;
18    }
19};
20
21
22
23/**
24 * Your MyCalendar object will be instantiated and called as such:
25 * MyCalendar* obj = new MyCalendar();
26 * bool param_1 = obj->book(startTime,endTime);
27 */