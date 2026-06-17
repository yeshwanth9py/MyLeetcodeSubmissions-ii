// Last updated: 6/17/2026, 2:15:14 PM
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        int prev = 0;
        for(int i=0; i<31; i++){
            if((n&(1<<i)) != 0){
                if(prev){
                    cnt++;
                }
                prev = 1;
            }else{
                prev = 0;
            }
        }

        return cnt == 1;
    }
};