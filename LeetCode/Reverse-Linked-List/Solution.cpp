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
11class Solution {
12public:
13    ListNode* reverseList(ListNode* head) {
14        if(head == nullptr){
15            return nullptr;
16        }
17        if(head->next == nullptr){
18            return head;
19        }
20
21        ListNode* newh = reverseList(head->next);
22        if(head->next){
23            head->next->next = head;
24        }
25        head->next = nullptr;
26
27        return newh;
28    }
29};