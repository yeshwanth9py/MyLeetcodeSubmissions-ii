1class MyCalendarThree {
2public:
3    vector<vector<int>> sweep; //{st, +1, en}
4    MyCalendarThree() {
5        sweep.clear();
6    }
7    int runsweep(){
8        int com = 0;
9        int mx = 0;
10        for(int i=0; i<sweep.size(); i++){
11            int st = sweep[i][0];
12            int ty = sweep[i][1];
13            int en = sweep[i][2];
14            if(ty == 1){
15                com++;
16                mx = max(mx, com);
17            }else{
18                com--;
19            }
20        }
21        return mx;
22    }
23    int book(int s, int e) {
24        e=e-1;
25        sweep.push_back({s, 1, e});
26        sweep.push_back({e, 2});
27        sort(sweep.begin(), sweep.end());
28        return runsweep();
29    }
30};
31
32/**
33 * Your MyCalendarThree object will be instantiated and called as such:
34 * MyCalendarThree* obj = new MyCalendarThree();
35 * int param_1 = obj->book(startTime,endTime);
36 */