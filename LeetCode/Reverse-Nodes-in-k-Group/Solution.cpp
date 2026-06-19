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
13    void reverseList(ListNode* head, ListNode* tail){
14        ListNode* prev = nullptr;
15        ListNode* cur = head;
16        while(cur){
17            ListNode* fut = cur->next;
18            cur->next = prev;
19            prev = cur;
20            cur = fut;
21        }
22    }
23
24    ListNode* reverseKGroup(ListNode* head, int k) {
25        ListNode* dumh = new ListNode(-1);
26        dumh->next = head;
27        ListNode* cur = dumh;
28        
29        while(1){
30            ListNode* ph = cur;
31            ListNode* curhead = cur->next;
32            
33            for(int i=0; i<k; i++){
34                if(cur){
35                    cur = cur->next;
36                } 
37            }
38            ListNode* tail = cur;
39            if(tail == nullptr) break;
40            // cout<<curhead->val<<" "<<tail->val<<endl;
41            ListNode* fut = tail->next;
42            tail->next = nullptr;
43            reverseList(curhead, tail);
44
45            ph->next = tail;
46            curhead->next = fut;
47
48            cur = curhead;
49        }
50
51        return dumh->next;
52    }
53};