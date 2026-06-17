// Last updated: 6/17/2026, 2:15:21 PM
class Solution {
public:
    int dp1[111];
    int dp2[111];
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> odds(k, 0), evens(k, 0);
        for(int i=0; i<n; i++){
            nums[i] = nums[i]%k;
            // cout<<nums[i]<<" ";
            if(i%2 == 0){
                evens[nums[i]]++;
            }else{
                odds[nums[i]]++;
            }
        }
        
        for(int el1=0; el1<k; el1++){
            int curop = 0;
            for(int i=0; i<k; i++){
                curop += evens[i]*min({abs(i-el1), (k-i)+el1, (k-el1+i)});
            }
            int curop2 = 0;
            for(int i=0; i<k; i++){
                curop2 += odds[i]*min({abs(i-el1), (k-i)+el1, (k-el1+i)});
            }
            dp1[el1] = curop;
            dp2[el1] = curop2;
        }

        int ans = 1e9;
        for(int el1=0; el1<k; el1++){
            for(int el2=0; el2<k; el2++){
                if(el1 == el2) continue;
                ans = min(ans, dp1[el1]+dp2[el2]);
            }
        }

        return ans;
        
    }
};