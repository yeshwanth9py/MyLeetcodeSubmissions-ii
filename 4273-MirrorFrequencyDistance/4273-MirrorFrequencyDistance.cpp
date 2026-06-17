// Last updated: 6/17/2026, 2:15:53 PM
class Solution {
public:
    int mirrorFrequency(string s) {
        map<char, int> ump;
        for(char ch: s){
            ump[ch]++;
        }
        
        int tot = 0;
        set<char> done;
        for(auto el: ump){
            char ch = el.first;
            if(ch>='0' && ch<='9'){
                char och = char(abs(ch-'9') + '0');
                if(done.find(och) != done.end()) continue;
                done.insert(ch);
                done.insert(och);
                // cout<<ch<<" "<<och<<" "<<abs(ump[och] - ump[ch])<<endl;
                tot += abs(ump[och] - ump[ch]);
            }else{
                int add = (25 - (ch-'a'));
                char och = char(add +'a');
                if(done.find(och) != done.end()) continue;
                done.insert(ch);
                done.insert(och);
                // cout<<ch<<" "<<och<<" "<<abs(ump[och] - ump[ch])<<endl;
                tot += abs(ump[och] - ump[ch]);
            }
            // cout<<ch<<endl;
            
            
        }

        return tot;

    }
};