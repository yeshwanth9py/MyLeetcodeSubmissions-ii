// Last updated: 6/17/2026, 2:15:29 PM
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string, int> ump;
        string bs = "";
        for(auto s: chunks){
            bs += s;
        }

        istringstream iss(bs);
        string temp;
        while(iss>>temp){
            string t = temp;
            
            while(t.size()>0 && t.back()=='-'){
                t.pop_back();
            }
            reverse(t.begin(), t.end());
            while(t.size()>0 && t.back()=='-'){
                t.pop_back();
            }
            reverse(t.begin(), t.end());
            
            string vw = "";
            int i = 0;

            bool prev = 0;
            for(int i=0; i<t.size(); i++){
                if(t[i] == '-'){
                    if(prev && i+1<t.size() && t[i+1]>='a' && t[i+1]<='z'){
                        vw.push_back(t[i]);
                    }else{
                        if(vw != "") ump[vw]++;
                        vw = "";
                    }
                    prev = 0;
                }else{
                    prev = 1;
                    vw.push_back(t[i]);
                }
            }

            if(vw != "") ump[vw]++;
        }

        vector<int> ans;
        for(auto s: queries){
            int noc = ump[s];
            ans.push_back(noc);
        }

        return ans;
        
    }
};