// Last updated: 6/17/2026, 2:15:27 PM
class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        vector<pair<int, int>> vec;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>i) continue;
            vec.push_back({nums[i], i-nums[i]});
        }

        sort(vec.begin(), vec.end(), [&](pair<int, int> &a, pair<int, int> &b){
            if(a.first != b.first) return a.first<b.first;
            return a.second>b.second;
        });

        vector<int> ans;
        for(int i=0; i<vec.size(); i++){
            if(i == 0 || ans.back()<=vec[i].second){
                ans.push_back(vec[i].second);
            }else{
                int it = upper_bound(ans.begin(), ans.end(), vec[i].second) - ans.begin();
                ans[it] = vec[i].second;
            }
        }

        return ans.size();
    }
};