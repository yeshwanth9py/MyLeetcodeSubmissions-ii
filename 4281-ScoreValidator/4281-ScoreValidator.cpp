// Last updated: 6/17/2026, 2:15:45 PM
class Solution {
public:
    vector<int> scoreValidator(vector<string>& eve) {
        int cnt = 0;
        int sc = 0;
        for(auto s: eve){
            if(s == "W"){
                cnt++;
                if(cnt>=10) return {sc, cnt};
            }else if(s == "WD"){
                sc++;
            }else if(s == "NB"){
                sc++;
            }else{
                sc += stoi(s);
            }
        }

        return {sc, cnt};
    }
};