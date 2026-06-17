// Last updated: 6/17/2026, 2:16:15 PM
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if(n != nums2.size()) return -1;
        unordered_map<int, int> pres1;
        unordered_map<int, int> pres2;

        unordered_map<int, int> all;
        
        for(int el: nums1){
            pres1[el]++;
            all[el]++;
        }

        for(int el: nums2){
            pres2[el]++;
            all[el]++;
        }

        for(auto el: all){
            if(el.second%2 == 1) return -1;
        }

        int ans = 0;
        for(auto el: all){
            int f = el.first;
            if(pres1[f] == pres2[f]) continue;
            int ex = abs(pres2[f]-pres1[f]);
            ans += ex/2;
        }
        return ans/2;
        
        
    }
};