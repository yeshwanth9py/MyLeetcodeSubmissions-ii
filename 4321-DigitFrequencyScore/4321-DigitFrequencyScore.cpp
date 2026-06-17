// Last updated: 6/17/2026, 2:15:05 PM
class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> ump;
        string s = to_string(n);
        for(char ch: s){
            ump[ch-'0']++;
        }
        int ans = 0;
        for(auto el: ump){
            ans += el.first*el.second;
        }

        return ans;
    }
};