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
12class Solution {
13public:
14    ListNode* mergeKLists(vector<ListNode*>& lists) {
15        ListNode* root = new ListNode(-1);
16        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq;
17        for(auto el: lists){
18            ListNode* cur = el;
19            if(cur != nullptr){
20                pq.push({cur->val, cur});
21            }
22        }
23
24        ListNode* cur = root;
25        while(!pq.empty()){
26            auto tel = pq.top(); pq.pop();
27            cur->next = tel.second;
28            if(tel.second->next != nullptr){
29                pq.push({tel.second->next->val, tel.second->next});
30            }
31            cur = cur->next;
32            cur->next = nullptr;
33        }
34
35        return root->next;
36    }
37};