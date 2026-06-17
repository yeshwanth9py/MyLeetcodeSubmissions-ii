// Last updated: 6/17/2026, 2:15:26 PM
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int odd = 0;
        int eve = 0;
        int ans = 0;
        vector<int> vec(nums.size(), 0);
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]%2){
                
                odd++;
                vec[i] = eve;
            }else{
                
                eve++;
                vec[i] = odd;
            }
        }
        return vec;
    }
};