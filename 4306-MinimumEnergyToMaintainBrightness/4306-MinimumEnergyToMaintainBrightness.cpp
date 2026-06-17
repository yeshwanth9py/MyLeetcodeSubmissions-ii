// Last updated: 6/17/2026, 2:15:15 PM
class Solution {
public:
    long long minEnergy(long long n, long long brightness, vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<long long>> brr;
        long long i=0;
        long long nn = arr.size();
        while(i<nn){
            long long j=i;
            long long st = arr[i][0];
            long long en = arr[i][1];
            while(j<nn && arr[j][0]<=en){
                en = max(en, 1LL*arr[j][1]);
                j++;
            }
            brr.push_back({st, en});
            i=j;
        }
        

        long long each = ceil(brightness/3.0);
        long long ans = 0;
        for(long long i=0; i<brr.size(); i++){
            long long len = brr[i][1] - brr[i][0] + 1;
            ans += each*len;
        }

        return ans;
        
    }
};