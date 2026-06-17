// Last updated: 6/17/2026, 2:16:10 PM
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        auto sortable = [&](int i, int j){
            int l;
            int prev = -1e9;

            int st = -1;
            for(l=i; l<=j; l++){
                if(nums[l]<prev){
                    if(st == -1){
                        st = l;
                    }else{
                        return make_pair(-1, -1);
                    }
                }
                prev = nums[l];
            }

            if(st == -1) return make_pair(nums[i], nums[j]);
            if(nums[i]>=nums[j]) return make_pair(nums[st], nums[st-1]);
            return make_pair(-1, -1);
        };

        for(int k=1; k<=n; k++){
            if(n%k == 0){
                bool cansort = 1;
                int i = 0;
                int prevmax = -1e9;
                while(i<n){
                    int j = i+k-1;
                    auto [curmin, curmx] = sortable(i, j);
                    if(curmin == -1 || curmin<prevmax){
                        cansort = 0;
                        break;
                    }
                    prevmax = curmx;
                    i = j+1;
                }

                if(cansort){
                    ans += k;
                }
            }
        }

        return ans;
    }
};