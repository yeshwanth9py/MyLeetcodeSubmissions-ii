// Last updated: 6/17/2026, 2:15:32 PM
class Solution {
public:
    vector<int> minCost(vector<int>& arr, vector<vector<int>>& que) {
        long long n = arr.size();
        vector<long long> right(n, 0);
        vector<long long> cntri(n, 0);
        
        right[0] = 0;
        cntri[0] = 0;
        
        for(long long i=1; i<n; i++){
            right[i] = right[i-1];
            cntri[i] = cntri[i-1];
            if(abs(arr[i]-arr[i-1]) < (i-2>=0?abs(arr[i-1]-arr[i-2]):1e18)  ){
                right[i] += abs(arr[i]-arr[i-1]);
                cntri[i] += 1;
            }
        }

        vector<long long> left(n, 0);
        vector<long long> cntli(n, 0);
        
        left[n-1] = 0;
        cntli[n-1] = 0;
        
        for(long long i=n-2; i>=0; i--){
            left[i] = left[i+1];
            cntli[i] = cntli[i+1];
            if(abs(arr[i+1]-arr[i])<=(i+2<n?abs(arr[i+1]-arr[i+2]):1e18)){
                left[i] += abs(arr[i+1]-arr[i]);
                cntli[i] += 1;
            }
        }

        // for(long long i=0; i<n; i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;

        vector<int> ans;
        for(auto q: que){
            long long l = q[0];
            long long r = q[1];
            if(l==r){
                ans.push_back(0);
            }
            else if(l<r){
                long long cur = abs(arr[r] - arr[l]) - (right[r] - right[l]) + (cntri[r] - cntri[l]);
                ans.push_back(cur);
            }else{
                long long cur = abs(arr[r] - arr[l]) - (left[r] - left[l]) + (cntli[r] - cntli[l]);
                // cout<< left[l]<<" "<< left[r]<<endl;
                ans.push_back(cur);
            }
        }

        return ans;

        
    }
};