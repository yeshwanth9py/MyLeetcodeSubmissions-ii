// Last updated: 6/17/2026, 2:16:05 PM
class Solution {
public:
    // int rec(int ind, int nop, int first){
    //     if(ind >= n){
    //         if(nop >= k) return 0;
    //         return 1e9;
    //     }
    //     if(dp[ind][nop][first] != -1) return dp[ind][nop][first];

    //     int ans = rec(ind+1, nop, first);
    //     //make peak
    //     int froi = ((ind+1<n)?ind+1:0);

    //     if((froi == 0 && first == 1)){
    //         ans = ans;
    //     }else{
    //         int mx = max(arr[froi], ind-1>=0?arr[ind-1]:arr.back());
    //         int curop = 0;
    //         if(mx>=arr[ind]){
    //             curop = mx-arr[ind]+1;
    //         }
    //         ans = min(ans, curop + rec(ind+2, nop+1, ((ind==0?1:first))));
    //     }
        
    //     return dp[ind][nop][first] = ans;
    // }

    int minOperations(vector<int>& arr, int k) {
        int n = arr.size();
        // memset(dp, -1, sizeof(dp));
        if(k>(n/2)){
            return -1;
        }
        vector<vector<vector<int>>> dp(3, vector<vector<int>>(k+3, vector<int>(2, 0)));

        for(int ind=n+1; ind>=0; ind--){
            for(int nop=k+1; nop>=0; nop--){
                for(int first=0; first<=1; first++){
                    if(ind >= n){
                        if(nop >= k){
                            dp[ind%3][nop][first] = 0;
                            continue;
                        }else{
                            dp[ind%3][nop][first] = 1e9;
                            continue;
                        }
                    }

                    int ans = dp[(ind+1)%3][nop][first];
                    //make peak
                    int froi = ((ind+1<n)?ind+1:0);

                    if((froi == 0 && first == 1)){
                        ans = ans;
                    }else{
                        int mx = max(arr[froi], ind-1>=0?arr[ind-1]:arr.back());
                        int curop = 0;
                        if(mx>=arr[ind]){
                            curop = mx-arr[ind]+1;
                        }
                        ans = min(ans, curop + dp[(ind+2)%3][((nop+1>=k)?k:nop+1)][((ind==0?1:first))]);
                    }

                    dp[ind%3][nop][first] = ans;
                }
            }
        }
        
        
        return dp[0][0][0];
    }
};