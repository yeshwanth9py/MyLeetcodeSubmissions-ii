1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    bool hasCycle(ListNode *head) {
12        ListNode* slow = head, *fast = head;
13
14        unordered_map<ListNode*, int> ump;
15        while(head){
16            if(ump.find(head) != ump.end()) return 1;
17            ump[head] = 1;
18            head = head->next;
19        }
20
21        return 0;
22    }
23};