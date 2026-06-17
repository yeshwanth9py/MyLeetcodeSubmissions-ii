// Last updated: 6/17/2026, 2:15:47 PM
class Solution {
public:
    vector<int> arr;
    int n;
    vector<vector<int>> adjl;
    bool isvalid(int mask){
        int li = mask & (-mask);
        li = log2(li);
        // cout<<mask<<" "<<li<<"\n";
        queue<int> q;
        int sm = arr[li];
        mask = (mask ^ (1<<li));
        q.push(li);
        while(!q.empty() && mask>0){
            int tel = q.front(); q.pop();
            for(int nei: adjl[tel]){
                if((mask & (1<<nei)) != 0){
                    mask = (mask ^ (1<<nei));
                    sm += arr[nei];
                    q.push(nei);
                }
            }
        }
        
        if(mask>0) return 0;
        return (sm%2 == 0);
    }
    
    
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        arr = nums;
        adjl.resize(n, vector<int>());
        for(auto el: edges){
            int u = el[0];
            int v = el[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        
        int ans = 0;
        for(int mask=1; mask<(1<<n); mask++){
            if(isvalid(mask)){
                ans++;
            }
        }

        return ans;
    }
};