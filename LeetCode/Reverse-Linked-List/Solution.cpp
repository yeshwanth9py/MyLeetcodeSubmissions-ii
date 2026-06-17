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
14        ListNode* prev = nullptr;
15        ListNode* cur = head;
16
17        while(cur){
18            ListNode* temp = cur->next;
19            cur->next = prev;
20            prev = cur;
21            cur = temp;
22        }
23
24        return prev;
25    }
26};