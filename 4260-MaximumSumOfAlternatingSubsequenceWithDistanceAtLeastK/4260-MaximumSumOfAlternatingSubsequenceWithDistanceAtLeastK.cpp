// Last updated: 6/17/2026, 2:16:06 PM
//seg i can do this all day
struct Seg{  
    vector<long long> t1;
    vector<long long> t0;
    Seg(long long n){
        t1.resize(4*n, 0);
        t0.resize(4*n, 0);
    }
    void update1(long long idx, long long l, long long r, long long pos, long long val){
        if(pos<l || pos>r) return;
        if(l == r){
            t1[idx] = max(t1[idx], val);
            return;
        }
        long long mid = (l+r)/2;
        update1(2*idx, l, mid, pos, val);
        update1(2*idx+1, mid+1, r, pos, val);
        t1[idx] = max(t1[2*idx], t1[2*idx+1]);
    }

    void update0(long long idx, long long l, long long r, long long pos, long long val){
        if(pos<l || pos>r) return;
        if(l == r){
            t0[idx] = max(t0[idx], val);
            return;
        }
        long long mid = (l+r)/2;
        update0(2*idx, l, mid, pos, val);
        update0(2*idx+1, mid+1, r, pos, val);
        t0[idx] = max(t0[2*idx], t0[2*idx+1]);
    }

    long long findmaxt1(long long idx, long long l, long long r, long long ql, long long qr){
        if(r<ql || qr<l) return 0;
        if(ql<=l && r<=qr) return t1[idx];
        long long mid = (l+r)/2;
        return max(findmaxt1(2*idx, l, mid, ql, qr), findmaxt1(2*idx+1, mid+1, r, ql, qr));
    }

    long long findmaxt0(long long idx, long long l, long long r, long long ql, long long qr){
        if(r<ql || qr<l) return 0;
        if(ql<=l && r<=qr) return t0[idx];
        long long mid = (l+r)/2;
        return max(findmaxt0(2*idx, l, mid, ql, qr), findmaxt0(2*idx+1, mid+1, r, ql, qr));
    }
};


class Solution {
public:
    long long n;
    vector<int> arr;
    long long k;
    long long dp[101000][2];
    
    long long rec(){
        Seg sg(1e5+5);
        
        for(long long ind=n-1; ind>=0; ind--){
            if(ind+k<n){
                sg.update1(1, 0, 1e5+4, arr[ind+k], dp[ind+k][1]);
                sg.update0(1, 0, 1e5+4, arr[ind+k], dp[ind+k][0]);
            }
            
            for(long long inc=0; inc<=1; inc++){
                long long sc = arr[ind];
                // for(long long j=ind+k; j<n; j++){
                //     if(inc){
                //         if(arr[j]>arr[ind]){
                //             long long cur = arr[ind] + dp[j][!inc];
                //             sc = max(sc, cur);
                //         }
                //     }else{
                //         if(arr[j]<arr[ind]){
                //             long long cur = arr[ind] + dp[j][!inc];
                //             sc = max(sc, cur);
                //         }
                //     }
                // }
                if(inc){
                    sc = max(sc, arr[ind]+sg.findmaxt0(1, 0, 1e5+4, arr[ind]+1, 1e5+4));
                }else{
                    sc = max(sc, arr[ind]+sg.findmaxt1(1, 0, 1e5+4, 0, arr[ind]-1));
                }
                
                dp[ind][inc] = sc;
            }
        }

        long long asans = 0;
        for(int i=0; i<n; i++){
            asans = max({asans, dp[i][0], dp[i][1]});
        }
        return asans;
    }
    
    long long maxAlternatingSum(vector<int>& nums, int kk) {
        n = nums.size();
        arr = nums;
        k = kk;
        memset(dp, 0, sizeof(dp));
        return rec();
    }
};