// Last updated: 6/17/2026, 2:15:39 PM
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxtn(n, -1e9);
        maxtn[0] = nums[0];
        for(int i=1; i<n; i++){
            maxtn[i] = max(maxtn[i-1], nums[i]);
        }
        vector<int> mintn(n, 1e9);
        mintn[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            mintn[i] = min(mintn[i+1], nums[i]);
        }

        for(int i=0; i<n; i++){
            int cur = maxtn[i] - mintn[i];
            if(cur<=k) return i;
        }

        return -1;

        //my own one idiots
    }
};