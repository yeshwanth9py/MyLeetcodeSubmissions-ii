// Last updated: 6/17/2026, 2:15:56 PM
class Solution {
public:
    long long minOperations(vector<int>& arr) {
        long long n = arr.size();
        long long ans = 0;
        for(long long i=1; i<n; i++){
            if(arr[i]>=arr[i-1]){
                continue;
            }else{
                long long inc = arr[i-1] - arr[i];
                ans += inc;
            }
        }

        return ans;
    }
};