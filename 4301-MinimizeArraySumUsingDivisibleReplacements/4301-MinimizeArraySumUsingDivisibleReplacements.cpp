// Last updated: 6/17/2026, 2:15:20 PM
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, long long> ump;
        int mx = nums.back();
        
        for(long long i=nums.size()-1; i>=0; i--){
            long long el = nums[i];
            if(ump.find(el) != ump.end()) continue;
            for(long long j=el; j<mx+4; j=j+el){
                if(ump.find(j) == ump.end()){
                    ump[j] = el;
                }else{
                    ump[j] = min(ump[j], el);
                }
            }
        }

        long long s = 0;
        for(long long el: nums){
            s += ump[el];
        }

        return s;
    }
};