// Last updated: 6/17/2026, 2:15:33 PM
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int mxntn = -1e9;
        vector<int> ans;
        int n = nums.size();
        
        vector<int> rmx(n, -1e9);
        rmx[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rmx[i] = max(rmx[i+1], nums[i]);
        }
        
        for(int i=0; i<n; i++){
            if(i==0 || i==n-1){
                ans.push_back(nums[i]);
            }else{
                if(nums[i]>mxntn || nums[i]>rmx[i+1]){
                    ans.push_back(nums[i]);
                }
            }
            mxntn = max(mxntn, nums[i]);
        }

        return ans;
    }
};