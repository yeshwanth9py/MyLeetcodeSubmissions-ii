1class Solution {
2public:
3    vector<int> seg;
4
5    /*
6        Build segment tree over the gain array.
7
8        gain[i] tells us the maximum number of new ones
9        obtained by selecting one-block i, assuming both
10        neighbouring zero blocks are completely available.
11    */
12    void build(
13        int ind,
14        int low,
15        int high,
16        vector<int>& gain
17    ) {
18        if(low == high) {
19            seg[ind] = gain[low];
20            return;
21        }
22
23        int mid = low + (high - low) / 2;
24
25        build(2 * ind + 1, low, mid, gain);
26        build(2 * ind + 2, mid + 1, high, gain);
27
28        seg[ind] = max(
29            seg[2 * ind + 1],
30            seg[2 * ind + 2]
31        );
32    }
33
34    /*
35        Return maximum gain in block-index range [ql, qr].
36    */
37    int getMaximum(
38        int ind,
39        int low,
40        int high,
41        int ql,
42        int qr
43    ) {
44        // No overlap
45        if(high < ql || low > qr) {
46            return 0;
47        }
48
49        // Complete overlap
50        if(ql <= low && high <= qr) {
51            return seg[ind];
52        }
53
54        // Partial overlap
55        int mid = low + (high - low) / 2;
56
57        int leftAnswer = getMaximum(
58            2 * ind + 1,
59            low,
60            mid,
61            ql,
62            qr
63        );
64
65        int rightAnswer = getMaximum(
66            2 * ind + 2,
67            mid + 1,
68            high,
69            ql,
70            qr
71        );
72
73        return max(leftAnswer, rightAnswer);
74    }
75
76    vector<int> maxActiveSectionsAfterTrade(
77        string s,
78        vector<vector<int>>& queries
79    ) {
80        int n = s.size();
81
82        /*
83            Count the total number of ones in the complete string.
84
85            Every answer starts with this value.
86
87            A trade only adds some previously-zero positions.
88            The selected one-block eventually becomes one again.
89        */
90        int totalOnes = 0;
91
92        for(char ch : s) {
93            if(ch == '1') {
94                totalOnes++;
95            }
96        }
97
98        /*
99            Store every maximal block of ones.
100
101            Example:
102            s = "001110011"
103
104            ones = {
105                {2, 4},
106                {7, 8}
107            };
108        */
109        vector<pair<int, int>> ones;
110
111        int start = -1;
112
113        for(int i = 0; i < n; i++) {
114            if(s[i] == '1') {
115                if(start == -1) {
116                    start = i;
117                }
118            } else {
119                if(start != -1) {
120                    ones.push_back({start, i - 1});
121                    start = -1;
122                }
123            }
124        }
125
126        // Handle a one-block ending at n-1
127        if(start != -1) {
128            ones.push_back({start, n - 1});
129        }
130
131        /*
132            prev0[i] =
133            number of consecutive zeros ending at i.
134
135            Example:
136            s = "1000"
137
138            prev0 = [0, 1, 2, 3]
139        */
140        vector<int> prev0(n, 0);
141
142        for(int i = 0; i < n; i++) {
143            if(s[i] == '0') {
144                prev0[i] = 1;
145
146                if(i > 0) {
147                    prev0[i] += prev0[i - 1];
148                }
149            }
150        }
151
152        /*
153            next0[i] =
154            number of consecutive zeros starting at i.
155
156            Example:
157            s = "0001"
158
159            next0 = [3, 2, 1, 0]
160        */
161        vector<int> next0(n, 0);
162
163        for(int i = n - 1; i >= 0; i--) {
164            if(s[i] == '0') {
165                next0[i] = 1;
166
167                if(i + 1 < n) {
168                    next0[i] += next0[i + 1];
169                }
170            }
171        }
172
173        int numberOfOneBlocks = ones.size();
174
175        /*
176            starts[i] = start of one-block i
177            ends[i]   = end of one-block i
178
179            These arrays are used for binary search.
180        */
181        vector<int> starts(numberOfOneBlocks);
182        vector<int> ends(numberOfOneBlocks);
183
184        /*
185            gain[i] = complete left zeros + complete right zeros
186        */
187        vector<int> gain(numberOfOneBlocks, 0);
188
189        for(int i = 0; i < numberOfOneBlocks; i++) {
190            int oneStart = ones[i].first;
191            int oneEnd = ones[i].second;
192
193            starts[i] = oneStart;
194            ends[i] = oneEnd;
195
196            /*
197                If the one-block touches the beginning or end
198                of the complete string, it does not have zeros
199                on both sides globally.
200
201                Such a block can never be strictly inside a query
202                with a zero on both sides.
203            */
204            if(oneStart > 0 && oneEnd + 1 < n) {
205                int completeLeftZeros =
206                    prev0[oneStart - 1];
207
208                int completeRightZeros =
209                    next0[oneEnd + 1];
210
211                gain[i] =
212                    completeLeftZeros +
213                    completeRightZeros;
214            }
215        }
216
217        /*
218            Build segment tree over one-block gains.
219        */
220        seg.assign(
221            4 * max(1, numberOfOneBlocks),
222            0
223        );
224
225        if(numberOfOneBlocks > 0) {
226            build(
227                0,
228                0,
229                numberOfOneBlocks - 1,
230                gain
231            );
232        }
233
234        vector<int> answer;
235
236        for(auto& currentQuery : queries) {
237            int l = currentQuery[0];
238            int r = currentQuery[1];
239
240            /*
241                Find first one-block satisfying:
242
243                    oneStart > l
244            */
245            int first =
246                upper_bound(
247                    starts.begin(),
248                    starts.end(),
249                    l
250                ) - starts.begin();
251
252            /*
253                Find last one-block satisfying:
254
255                    oneEnd < r
256            */
257            int last =
258                lower_bound(
259                    ends.begin(),
260                    ends.end(),
261                    r
262                ) - ends.begin() - 1;
263
264            /*
265                If first > last, there is no one-block
266                strictly inside the query.
267            */
268            if(first > last) {
269                answer.push_back(totalOnes);
270                continue;
271            }
272
273            /*
274                Calculate the exact gain of a boundary candidate.
275
276                Unlike a middle candidate, its neighbouring
277                zero block may be partially outside the query.
278            */
279            auto calculateExactGain = [&](int blockIndex) {
280                int oneStart = ones[blockIndex].first;
281                int oneEnd = ones[blockIndex].second;
282
283                /*
284                    Complete number of consecutive zeros
285                    before this one-block.
286                */
287                int completeLeftZeros =
288                    prev0[oneStart - 1];
289
290                /*
291                    But only oneStart-l positions are present
292                    before it inside this query.
293                */
294                int availableLeftPositions =
295                    oneStart - l;
296
297                int leftZeros = min(
298                    completeLeftZeros,
299                    availableLeftPositions
300                );
301
302                /*
303                    Complete number of consecutive zeros
304                    after this one-block.
305                */
306                int completeRightZeros =
307                    next0[oneEnd + 1];
308
309                /*
310                    But only r-oneEnd positions are present
311                    after it inside this query.
312                */
313                int availableRightPositions =
314                    r - oneEnd;
315
316                int rightZeros = min(
317                    completeRightZeros,
318                    availableRightPositions
319                );
320
321                return leftZeros + rightZeros;
322            };
323
324            int bestGain = 0;
325
326            /*
327                First valid block may be clipped from the left.
328            */
329            bestGain = max(
330                bestGain,
331                calculateExactGain(first)
332            );
333
334            /*
335                Last valid block may be clipped from the right.
336
337                If first == last, this simply calculates the
338                same block again, which is harmless.
339            */
340            bestGain = max(
341                bestGain,
342                calculateExactGain(last)
343            );
344
345            /*
346                Candidates strictly between first and last
347                have complete zero blocks on both sides.
348
349                Therefore, use their precomputed gains.
350            */
351            int middleLeft = first + 1;
352            int middleRight = last - 1;
353
354            if(middleLeft <= middleRight) {
355                int middleBest = getMaximum(
356                    0,
357                    0,
358                    numberOfOneBlocks - 1,
359                    middleLeft,
360                    middleRight
361                );
362
363                bestGain = max(
364                    bestGain,
365                    middleBest
366                );
367            }
368
369            answer.push_back(
370                totalOnes + bestGain
371            );
372        }
373
374        return answer;
375    }
376};