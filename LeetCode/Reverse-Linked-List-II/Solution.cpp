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
13    ListNode* reverselist(ListNode* head){
14        if(head == nullptr){
15            return head;
16        }
17        if(head->next == nullptr){
18            return head;
19        }
20        ListNode* newh = reverselist(head->next);
21        head->next->next = head;
22        head->next = nullptr;
23        return newh;
24        return nullptr;
25    }
26
27    ListNode* reverseBetween(ListNode* head, int left, int right) {
28        ListNode* dumh = new ListNode(-1);
29        dumh->next = head;
30        ListNode* l = dumh;
31        ListNode* r = dumh;
32
33        for(int i=1; i<left; i++){
34            l = l->next;
35        }
36        for(int i=1; i<=right; i++){
37            r = r->next;
38        }
39
40        ListNode* revh = l->next;
41        ListNode* futr = r->next;
42        l->next = nullptr;
43        r->next = nullptr;
44        reverselist(revh);
45
46        revh->next = futr;
47        l->next = r;
48
49        return dumh->next;
50    }
51};