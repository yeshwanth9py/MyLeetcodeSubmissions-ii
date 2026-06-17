// Last updated: 6/17/2026, 2:15:49 PM
class Solution {
public:
    const long long mod = 1e9+7;
    int dp[500100];
    long long binpow(long long x, long long n){
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        long long ans= binpow(x, n/2);
        ans = ((1LL*ans*ans)%mod + mod)%mod;
        if(n&1){
            ans = ((1LL*ans*x)%mod + mod)%mod;
        }
        return dp[n] = ans;
    }
    
    int maxValue(vector<int>& arr1, vector<int>& arr0) {
        vector<pair<long long, long long>> temp;
        long long n = arr1.size();
        memset(dp, -1, sizeof(dp));
        for(long long i=0; i<n; i++){
            temp.push_back({arr1[i], arr0[i]});
        }
        sort(temp.begin(), temp.end(), [&](pair<long long, long long> &a, pair<long long, long long> &b){
            if(a.second == 0 || b.second == 0){
                return a.second<b.second;
            }else if(a.first != b.first){
                return a.first>b.first;
            }else{
                return a.second<b.second;
            }
        });

        long long ans = 0;
        long long ind = 0;
        for(long long i=temp.size()-1; i>=0; i--){
            auto [f, l] = temp[i];
            ind = ind+l;
            for(long long j=0; j<f; j++){
                ans = ((ans + binpow(2, ind))%mod + mod)%mod;
                ind++;
            }
        }

        return ans;

        
    }
};