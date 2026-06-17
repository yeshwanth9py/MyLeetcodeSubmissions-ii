// Last updated: 6/17/2026, 2:15:08 PM
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int noz = 0;
        for(int el: nums){
            if(el == 0){
                noz++;
            }
        }

        int ans = 0;
        for(int i=0; i<n-noz; i++){
            if(nums[i] == 0) ans++;
        }

        return ans;

        
    }
};