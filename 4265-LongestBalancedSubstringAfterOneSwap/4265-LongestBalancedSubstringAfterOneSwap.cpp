// Last updated: 6/17/2026, 2:16:02 PM
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> p0(n, 0); 
        vector<int> p1(n, 0);
        vector<int> n0(n, 0); 
        vector<int> n1(n, 0);

        int ans = 0;

        int curs = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                curs--;
                p0[i] = 1;
            }else{
                curs++;
                p1[i] = 1;
            }
            p0[i] += (i-1>=0?p0[i-1]:0);
            p1[i] += (i-1>=0?p1[i-1]:0);
        }

        curs = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                curs--;
                n0[i] = 1;
            }else{
                curs++;
                n1[i] = 1;
            }
            n0[i] += (i+1<n?n0[i+1]:0);
            n1[i] += (i+1<n?n1[i+1]:0);
        }

        unordered_map<int, vector<int>> ump;

        curs = 0;
        ump[0].push_back(-1);
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                curs--;
            }else{
                curs++;
            }
            if(curs == 0){
                ans = max(ans, i+1);
            }
            if(ump.find(curs) != ump.end()){
                ans = max(ans, i-ump[curs][0]);
            }
            if(ump.find(curs-2) != ump.end()){
                for(int j: ump[curs-2]){
                    if(((j>=0 && p0[j]>0) || (i+1<n && n0[i+1]>0))){
                        ans = max(ans, i-j);
                        break;
                    }
                }
            }
            if(ump.find(curs+2) != ump.end()){
                for(int j: ump[curs+2]){
                    if(((j>=0 && p1[j]>0) || (i+1<n && n1[i+1]>0))){
                        ans = max(ans, i-j);
                        break;
                    }
                }
            }

            ump[curs].push_back(i);
        }
        

        return ans;
    }
};