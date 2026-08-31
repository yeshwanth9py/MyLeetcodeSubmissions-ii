1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11
12
13class Solution {
14public:
15    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
16        vector<int> dist;
17        ListNode* cur = head;
18
19        int prev = -1;
20        int ind = 0;
21        while(cur){
22            if(cur && prev != -1 && cur->next){
23                if(cur->val<prev && cur->val<(cur->next->val)){
24                    dist.push_back(ind);
25                }else if(cur->val>prev && cur->val>(cur->next->val)){
26                    dist.push_back(ind);
27                }
28            }
29            ind++;
30            prev = cur->val;
31            cur = cur->next;
32        }
33
34        if(dist.size()<2) return {-1, -1};
35        int mind = 1e9;
36        int maxd = -1e9;
37        for(int i=1; i<dist.size(); i++){
38            int curd = dist[i] - dist[i-1];
39            mind = min(mind, curd);
40        }
41        maxd = dist[dist.size()-1] - dist[0];
42
43        return {mind, maxd};
44    }
45};