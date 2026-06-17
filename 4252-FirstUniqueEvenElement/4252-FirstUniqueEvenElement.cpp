// Last updated: 6/17/2026, 2:16:16 PM
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int el: nums){
            ump[el]++;
        }

        for(int el: nums){
            if(el%2 == 0 && ump[el] == 1) return el;
        }
        return -1;
        
    }
};