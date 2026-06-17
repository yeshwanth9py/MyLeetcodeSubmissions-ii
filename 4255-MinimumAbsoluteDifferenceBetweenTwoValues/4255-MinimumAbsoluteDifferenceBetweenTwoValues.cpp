// Last updated: 6/17/2026, 2:16:13 PM
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int p2 = -1;
        int p1 = -1;
        int n = nums.size();
        int ans = 1e9;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                if(p2 != -1){
                    ans = min(ans, abs(p2-i));
                }
                p1 = i;
            }
            if(nums[i] == 2){
                if(p1 != -1){
                    ans = min(ans, abs(p1-i));
                }
                p2 = i;
            }
        }

        if(ans >= 1e8) return -1;

        return ans;
    }
};