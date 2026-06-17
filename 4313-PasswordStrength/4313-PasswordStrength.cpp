// Last updated: 6/17/2026, 2:15:10 PM
class Solution {
public:
    int passwordStrength(string s) {
        unordered_map<char, int> ump;
        int ans = 0;
        for(char ch: s){
            if(ump.find(ch) != ump.end()) continue;
            ump[ch]++;
            if(ch>='a' && ch<='z'){
                ans++;
            }else if(ch>='A' && ch<='Z'){
                ans += 2;
            }else if(ch>='0' && ch<='9'){
                ans += 3;
            }else{
                ans += 5;
            }
        }

        return ans;
    }
};