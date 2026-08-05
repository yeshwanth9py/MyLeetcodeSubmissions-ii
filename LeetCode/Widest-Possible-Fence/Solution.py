1from collections import defaultdict
2
3class Solution:
4    def maximumWidth(self, arr: list[int]) -> int:
5        n = len(arr)
6        mp = defaultdict(set)
7        scr = defaultdict(int)
8        
9        for i in range(n):
10            if i not in mp[arr[i]]:
11                mp[arr[i]].add(i)
12                scr[arr[i]] += 1
13                
14            for j in range(i + 1, n):
15                val = arr[i] + arr[j]
16                if i not in mp[val] and j not in mp[val]:
17                    mp[val].add(i)
18                    mp[val].add(j)
19                    scr[val] += 1
20
21        mxsz = 0
22        for key in mp:
23            mxsz = max(mxsz, scr[key])
24            
25        return mxsz