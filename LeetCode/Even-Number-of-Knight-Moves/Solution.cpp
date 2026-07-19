1class Solution {
2public:
3    bool canReach(vector<int>& start, vector<int>& target) {
4        return (start[0] + start[1])%2 == (target[0] + target[1])%2;
5    }
6};