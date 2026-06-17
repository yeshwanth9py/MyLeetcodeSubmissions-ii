// Last updated: 6/17/2026, 2:15:35 PM
class Solution {
public:
    int n;
    vector<string> ans;
    int k;
    void rec(int ind, int prev, int cos, string &s){
        if(cos>k) return;
        if(ind == n){
            if(cos<=k){
                ans.push_back(s);
            }
            return;
        }
        
        s.push_back('0');
        rec(ind+1, 0, cos, s);
        s.pop_back();

        if(ind == 0 || prev == 0){
            s.push_back('1');
            rec(ind+1, 1, cos+ind, s);
            s.pop_back();
        }
    
    }
    vector<string> generateValidStrings(int nn, int kk) {
        n = nn;
        k = kk;
        string s = "";
        ans.clear();

        rec(0, 0, 0, s);

        return ans;
    }
};