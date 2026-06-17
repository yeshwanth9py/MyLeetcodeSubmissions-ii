// Last updated: 6/17/2026, 2:15:57 PM
class Solution {
public:
    vector<int> all;
    vector<int> findGoodIntegers(int n) {
        for(int i=1; i*i*i<=n+10; i++){
            all.push_back(i*i*i);
        }

        unordered_map<int, int> ump;
        vector<int> ans;
        
        for(int i=1; i*i*i<=n+10; i++){
            int curc = i*i*i;
            for(int j=i+1; j*j*j<=n+10; j++){
                int othc = j*j*j;
                if(curc+othc>n){
                    break;
                }else{
                    ump[(othc+curc)]++;
                }
            }
        }
        
        for(auto el: ump){
            if(el.second>=2){
                ans.push_back(el.first);
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};


