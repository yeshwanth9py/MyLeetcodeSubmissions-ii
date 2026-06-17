// Last updated: 6/17/2026, 2:15:52 PM
class Solution {
public:
    string trafficSignal(int t) {
        if(t==0) return "Green";
        if(t == 30) return "Orange";
        if(t>30 && t<=90) return "Red";
        return "Invalid";
    }
};