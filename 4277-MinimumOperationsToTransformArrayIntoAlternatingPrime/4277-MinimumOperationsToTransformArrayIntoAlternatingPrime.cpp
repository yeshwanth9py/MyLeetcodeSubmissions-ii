// Last updated: 6/17/2026, 2:15:50 PM
class Solution {
public:
    vector<int> isprim;
    vector<int> allp;
    vector<int> allnonp;
    void pre(){
        isprim.resize(1e5+15, 1);
        for(int i=2; i*i<=1e5+14; i++){
            if(isprim[i]){
                for(int j=i*i; j<=1e5+14; j=j+i){
                    isprim[j] = 0;
                }
            }
        }
        isprim[1] = 0;
        for(int i=2; i<=1e5+14; i++){
            if(isprim[i]){
                allp.push_back(i);
            }else{
                allnonp.push_back(i);
            }
        }
    }
    int minOperations(vector<int>& nums) {
        pre();
        int n = nums.size();

        int ans = 0;
        for(int i=0; i<n; i++){
            int el = nums[i];
            if(i%2 == 0){
                if(!isprim[el]){
                    auto it = lower_bound(allp.begin(), allp.end(), el);
                    int ty1 = (*it)-el;
                    ans += ty1;
                }
            }else{
                if(isprim[el]){
                    auto it = lower_bound(allnonp.begin(), allnonp.end(), el);
                    int ty1 = (*it)-el;
                    ans += ty1;
                }
            }
            // cout<<ans<<" ";
        }

        return ans;
        
        
    }
};


