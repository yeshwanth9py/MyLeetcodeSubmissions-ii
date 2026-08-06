1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string, vector<string>> ump;
5        for(auto el: strs){
6            string temp = el;
7            sort(el.begin(), el.end());
8            ump[el].push_back(temp);
9        }
10
11        vector<vector<string>> ans;
12
13        for(auto el: ump){
14            ans.push_back(el.second);
15        }
16
17        return ans;
18
19        
20
21    }
22};