1#include <vector>
2#include <algorithm>
3
4class Solution {
5public:
6    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
7        // Custom comparator for sorting
8        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
9            if (a[0] == b[0]) {
10                return a[1] > b[1]; // Descending order of end point if start points are equal
11            }
12            return a[0] < b[0]; // Ascending order of start point
13        });
14        
15        int remainingCount = 0;
16        int prevEnd = 0;
17        
18        for (const auto& interval : intervals) {
19            // If the current interval's end point extends past the previous maximum end point,
20            // it means this interval is NOT covered by any preceding interval.
21            if (interval[1] > prevEnd) {
22                remainingCount++;
23                prevEnd = interval[1]; // Update the maximum right endpoint tracked
24            }
25        }
26        
27        return remainingCount;
28    }
29};