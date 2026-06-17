// Last updated: 6/17/2026, 2:15:12 PM
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        vector<int> ans;
        for(int el: nums){
            ump[el]++;
            if(ump[el]<=k){
                ans.push_back(el);
            }
        }

        return ans;
    }
};