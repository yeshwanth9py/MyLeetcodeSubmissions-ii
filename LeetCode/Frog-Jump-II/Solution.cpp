1#include <vector>
2#include <algorithm>
3
4class Solution {
5public:
6    int maxJump(std::vector<int>& arr) {
7        // Base case for 2 elements
8        int max_jump = arr[1] - arr[0]; 
9        
10        // Alternate jumps (i to i-2)
11        for (int i = 2; i < arr.size(); i++) {
12            max_jump = std::max(max_jump, arr[i] - arr[i - 2]);
13        }
14        
15        return max_jump;
16    }
17};