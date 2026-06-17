// Last updated: 6/17/2026, 2:15:36 PM
class Solution {
public:
    vector<long long> eve;
    vector<int> nums;
    long long findbtw(long long l, long long r, long long val){
        if(val<nums[l]) return 0;
        if(val>nums[r]){
            return eve[r]-(l-1>=0?eve[l-1]:0);
        }
        int it = lower_bound(nums.begin(), nums.end(), val) - nums.begin();
        if(it == 0){
            if(nums[0] == val) return 1;
            return 0;
        }
        int ex = 0;
        if(nums[it] == val){
            ex = 1;
        }
        it--;
        return eve[it] - (l-1>=0?eve[l-1]:0) + ex;
    }
    
    long long check(long long ep, long long ap, long long l, long long r){
        long long ntbskp = (ep-ap)/2;
        long long actskp = findbtw(l, r, ep);
        if(actskp<=ntbskp) return 1;
        return 0;
    }
    
    vector<int> kthRemainingInteger(vector<int> &nums, vector<vector<int>> &queries) {
        vector<int> asans;
        this->nums = nums;
        eve.resize(nums.size(), 0);

        for(long long i=0; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                eve[i] = (i-1>=0?eve[i-1]:0) + 1;
            }else{
                eve[i] = (i-1>=0?eve[i-1]:0);
            }
        }
        
        for(auto el: queries){
            long long l = el[0];
            long long r = el[1];
            long long k = el[2];

            long long lo = k;
            long long hi = 1e18;
            long long ans = lo;
            while(lo<=hi){
                long long mid = (lo+hi)/2;
                if(check(2*mid, 2*k, l, r)){ //expected val, possible value, l, r
                    ans = mid;
                    hi = mid-1;
                }else{
                    lo = mid+1;
                }
            }

            asans.push_back(2*ans);
        }

        return asans;
    }
};