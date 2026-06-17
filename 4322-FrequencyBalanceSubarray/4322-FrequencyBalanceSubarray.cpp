// Last updated: 6/17/2026, 2:15:04 PM
class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        unordered_map<int, int> ump;
        // multiset<int> ms;
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){

            int fn1 = -1;
            int fn2 = -1;

            freq.clear();
            ump.clear();
            
            for(int j=i; j<n; j++){
                if(ump[nums[j]]>0){
                    freq[ump[nums[j]]]--;
                    if(freq[ump[nums[j]]] == 0){
                        freq.erase(ump[nums[j]]);
                    }
                }
                ump[nums[j]]++;
                if(nums[j] != fn1 && nums[j] != fn2){
                    if(fn1 == -1){
                        fn1 = nums[j];
                    }else if(fn2 == -1){
                        fn2 = nums[j];
                    }
                }
                
                freq[ump[nums[j]]]++;
                if(freq.size() == 1 && fn2 == -1 && fn1 > 0){
                    ans = max(ans, j-i+1);
                }else if(freq.size() == 2){
                    auto it = freq.begin();
                    int v1 = (*(it)).first;
                    it++;
                    int v2 = (*(it)).first;
                    
                    if((2*v1 == v2) || (2*v2 == v1)){
                        ans = max(ans, j-i+1);
                    }
                }
            }
        }

        return ans;
    }
};