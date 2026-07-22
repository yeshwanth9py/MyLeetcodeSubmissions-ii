1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5    class SegmentTree {
6        int n;
7        vector<int> tree;
8
9        void build(int node, int left, int right,
10                   const vector<int>& arr) {
11            if (left == right) {
12                tree[node] = arr[left];
13                return;
14            }
15
16            int mid = left + (right - left) / 2;
17
18            build(2 * node, left, mid, arr);
19            build(2 * node + 1, mid + 1, right, arr);
20
21            tree[node] = max(tree[2 * node],
22                             tree[2 * node + 1]);
23        }
24
25        int query(int node, int left, int right,
26                  int queryLeft, int queryRight) {
27            // No overlap
28            if (right < queryLeft || queryRight < left) {
29                return 0;
30            }
31
32            // Complete overlap
33            if (queryLeft <= left && right <= queryRight) {
34                return tree[node];
35            }
36
37            // Partial overlap
38            int mid = left + (right - left) / 2;
39
40            return max(
41                query(2 * node, left, mid,
42                      queryLeft, queryRight),
43
44                query(2 * node + 1, mid + 1, right,
45                      queryLeft, queryRight)
46            );
47        }
48
49    public:
50        SegmentTree(const vector<int>& arr) {
51            n = arr.size();
52
53            tree.assign(4 * max(1, n), 0);
54
55            if (n > 0) {
56                build(1, 0, n - 1, arr);
57            }
58        }
59
60        int query(int left, int right) {
61            if (n == 0 || left > right) {
62                return 0;
63            }
64
65            return query(1, 0, n - 1, left, right);
66        }
67    };
68
69public:
70    vector<int> maxActiveSectionsAfterTrade(
71        string s,
72        vector<vector<int>>& queries
73    ) {
74        int n = s.size();
75
76        // Number of active positions in the original string.
77        int totalOnes = count(s.begin(), s.end(), '1');
78
79        // Required variable mentioned in the problem statement.
80        string relominexa = s;
81
82        /*
83            Store every complete zero-block.
84
85            Example:
86
87            s = "1000110010"
88
89            Zero-blocks:
90            index 0 -> positions [1, 3], length 3
91            index 1 -> positions [6, 7], length 2
92            index 2 -> position  [9, 9], length 1
93        */
94        vector<int> zeroStart;
95        vector<int> zeroEnd;
96        vector<int> zeroLength;
97
98        /*
99            groupAt[i] = zero-block containing index i.
100
101            groupAt[i] remains -1 when s[i] == '1'.
102        */
103        vector<int> groupAt(n, -1);
104
105        for (int i = 0; i < n;) {
106            if (s[i] == '1') {
107                i++;
108                continue;
109            }
110
111            int start = i;
112            int groupIndex = zeroLength.size();
113
114            while (i < n && s[i] == '0') {
115                groupAt[i] = groupIndex;
116                i++;
117            }
118
119            int end = i - 1;
120
121            zeroStart.push_back(start);
122            zeroEnd.push_back(end);
123            zeroLength.push_back(end - start + 1);
124        }
125
126        int numberOfGroups = zeroLength.size();
127
128        /*
129            nextGroup[i] = first zero-block that intersects
130                           position i or comes after i.
131        */
132        vector<int> nextGroup(n, -1);
133
134        int next = -1;
135
136        for (int i = n - 1; i >= 0; i--) {
137            if (groupAt[i] != -1) {
138                next = groupAt[i];
139            }
140
141            nextGroup[i] = next;
142        }
143
144        /*
145            previousGroup[i] = last zero-block that intersects
146                               position i or comes before i.
147        */
148        vector<int> previousGroup(n, -1);
149
150        int previous = -1;
151
152        for (int i = 0; i < n; i++) {
153            if (groupAt[i] != -1) {
154                previous = groupAt[i];
155            }
156
157            previousGroup[i] = previous;
158        }
159
160        /*
161            pairSum[i] stores the sum of two consecutive
162            complete zero-blocks:
163
164            pairSum[i] =
165                zeroLength[i] + zeroLength[i + 1]
166        */
167        vector<int> pairSum;
168
169        for (int i = 0; i + 1 < numberOfGroups; i++) {
170            pairSum.push_back(
171                zeroLength[i] + zeroLength[i + 1]
172            );
173        }
174
175        SegmentTree segmentTree(pairSum);
176
177        vector<int> answer;
178
179        for (const vector<int>& query : queries) {
180            int left = query[0];
181            int right = query[1];
182
183            int firstGroup = nextGroup[left];
184            int lastGroup = previousGroup[right];
185
186            /*
187                A trade requires two different zero-blocks
188                with a one-block between them.
189
190                If the query contains fewer than two zero-blocks,
191                no valid trade is possible.
192            */
193            if (firstGroup == -1 ||
194                lastGroup == -1 ||
195                firstGroup >= lastGroup) {
196
197                answer.push_back(totalOnes);
198                continue;
199            }
200
201            /*
202                The first zero-block may begin before left.
203
204                Therefore, count only its part inside [left, right].
205            */
206            int firstPart =
207                min(zeroEnd[firstGroup], right) -
208                max(zeroStart[firstGroup], left) + 1;
209
210            /*
211                The last zero-block may end after right.
212
213                Therefore, count only its part inside [left, right].
214            */
215            int lastPart =
216                min(zeroEnd[lastGroup], right) -
217                max(zeroStart[lastGroup], left) + 1;
218
219            int bestGain = 0;
220
221            /*
222                Candidate 1:
223                Use the first and second zero-blocks.
224
225                If there are exactly two zero-blocks,
226                both may be partial.
227            */
228            if (firstGroup + 1 == lastGroup) {
229                bestGain = firstPart + lastPart;
230            } else {
231                bestGain =
232                    firstPart +
233                    zeroLength[firstGroup + 1];
234            }
235
236            /*
237                Candidate 2:
238                Use the last two zero-blocks.
239            */
240            if (lastGroup - 1 != firstGroup) {
241                bestGain = max(
242                    bestGain,
243                    zeroLength[lastGroup - 1] + lastPart
244                );
245            }
246
247            /*
248                Candidate 3:
249                Both zero-blocks are completely inside
250                the query.
251
252                pairSum[i] represents zero-blocks i and i+1.
253            */
254            int internalLeft = firstGroup + 1;
255            int internalRight = lastGroup - 2;
256
257            if (internalLeft <= internalRight) {
258                bestGain = max(
259                    bestGain,
260                    segmentTree.query(
261                        internalLeft,
262                        internalRight
263                    )
264                );
265            }
266
267            answer.push_back(totalOnes + bestGain);
268        }
269
270        return answer;
271    }
272};