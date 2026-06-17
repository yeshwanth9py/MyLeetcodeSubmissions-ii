// Last updated: 6/17/2026, 2:15:43 PM


class Solution {
public:
    bool isvow(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
        return 0;
    }

    string sortVowels(string s) {
        map<char, int> ump;
        int n = s.size();
        for(char ch: s){
            if(isvow(ch)) ump[ch]++;
        }
        vector<vector<int>> vec;  //f, fp, ch
        unordered_map<int, int> added;

        for(int i=0; i<s.size(); i++){
            if(!isvow(s[i])) continue;
            if(!added[s[i] - 'a']){
                vec.push_back({ump[s[i]], i, s[i]-'a'});
            }
            added[s[i]-'a'] = 1;
        }
        sort(vec.begin(), vec.end(), [&](vector<int> &a, vector<int> &b){
            if(a[0] != b[0]) return a[0]>b[0];
            return a[1]<b[1];
        });
            
        int j = 0;
        
        for(int i=0; i<n; i++){
            if(isvow(s[i])){
                s[i] = char(vec[j][2] + 'a');
                ump[s[i]]--;
                if(ump[s[i]] == 0){
                    j++;
                }
            }
        }

        return s;
            
    }
};