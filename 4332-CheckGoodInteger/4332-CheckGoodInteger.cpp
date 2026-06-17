// Last updated: 6/17/2026, 2:15:07 PM
class Solution {
public:
    bool checkGoodInteger(int n) {
        int ds = 0;
        int ss = 0;
        while(n>0){
            int ld = n%10;
            ds += ld;
            ss += (ld*ld);
            n = n/10;
        }
        return (ss-ds)>=50;
    }
};