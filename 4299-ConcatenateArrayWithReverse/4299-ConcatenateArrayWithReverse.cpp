// Last updated: 6/17/2026, 2:15:23 PM
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> onums = nums;
        for(int i=nums.size()-1; i>=0; i--){
            onums.push_back(nums[i]);
        }

        return onums;
    }
};