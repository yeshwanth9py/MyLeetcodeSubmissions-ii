// Last updated: 6/17/2026, 2:16:07 PM
class Solution {
public:
    int ds[5011];
    int n;
    vector<int> dis;
    int dp[1001][5011];
    const int mod = 1e9+7;

    int findsum(int num){
        int dnum = num;
        ds[num] = 0;
        while(dnum){
            ds[num] += dnum%10;
            dnum = dnum/10;
        }
        return ds[num];
    }

    int rec(){
        // if(ind == n){
        //     return 1;
        // }
        // if(dp[ind][prev] != -1) return dp[ind][prev];
        // int ways = 0;
        // for(int cur=prev; cur<5001; cur++){
        //     if(ds[cur] == dis[ind]){
        //         ways += rec(ind+1, cur);
        //     }
        // }

        // return dp[ind][prev] = ways;
        // vector<vector<int>> pref(50, vector<int>(5011, 0));
        for(int ind=n; ind>=0; ind--){
            // vector<vector<int>> preffut(50, vector<int>(5011, 0));
            for(int prev = 5000; prev>=0; prev--){
                if(ind == n){
                    dp[ind][prev] = 1;
                }else{
                     
                    // for(int cur=prev; cur<5001; cur++){
                    //     if(ds[cur] == dis[ind]){
                    //         ways += dp[ind+1][cur];
                    //     }
                    // }
                    //dp[ind][prev] = dp[ind+1][prev] + dp[ind+1][prev+1] + dp[ind+1][prev+2] + ...
                    //dp[ind][prev+1] = dp[ind+1][prev+1] + dp[ind+1][prev+2] + ...
                    //dp[ind][prev] = dp[ind+1][prev] + dp[ind][prev+1];
                    int ways = ((((ds[prev] == dis[ind])?dp[ind+1][prev]:0) + dp[ind][prev+1])%mod + mod)%mod;
                    dp[ind][prev] = ways;
                }

                // for(int i=0; i<40; i++){
                //     preffut[i][prev] += preffut[i][prev+1];
                //     if(i == ds[prev]){
                //         preffut[i][prev] += dp[ind][prev];
                //     }
                // }
            }
            // swap(pref, preffut);
        }

        return dp[0][0];
    }


    int countArrays(vector<int>& dis) {
        for(int i=0; i<=5010; i++){
            ds[i] = findsum(i);
        }
        this->dis = dis;

        n = dis.size();

        return rec();

    }
};