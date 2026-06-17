// Last updated: 6/17/2026, 2:15:18 PM
class Solution {
public:
    long long binpow(long long x, long long n){
        if(n == 0) return 1;
        long long ans = binpow(x, n/2);
        ans = ans*ans;
        if(n&1){
            ans = ans*x;
        }
        return ans;
    }
    
    int countKthRoots(int l, int r, int k) {
        if(r <= 0) return 1;
        long long lo = 0;
        long long hi = ceil((log2(r)/k)+1)+1;
        hi = binpow(2, hi);
        long long mx = hi;
        long long ansl = -1;
        long long ansr = -1;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            long long val = binpow(mid, k);
            if(val>=l && val<=r){
                ansl = mid;
                hi = mid-1;
            }else if(val<l){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        if(ansl == -1) return 0;
        
        lo = ansl;
        hi = mx;
        
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            long long val = binpow(mid, k);
            if(val>=l && val<=r){
                // cout<<val<<" "<<l<<" "<<r<<endl;
                ansr = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        // cout<<binpow(ansr, k)<<endl;
        // cout<<ansl<<" "<<ansr<<endl;
        
        return ansr-ansl+1;
        
    }
};