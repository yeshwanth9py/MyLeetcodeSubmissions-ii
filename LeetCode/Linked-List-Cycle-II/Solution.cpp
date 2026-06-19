1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9
10 
11 //L + X,   L + N*C + X
12 //  N*C = L + X
13 //  C + (N-1)*C = L+X
14 //  C-X + (N-1)*C = L 
15
16class Solution {
17public:
18    ListNode *detectCycle(ListNode *head) {
19        ListNode* slow = head;
20        ListNode* fast = head;
21
22        while(fast && fast->next){
23            slow = slow->next;
24            fast = fast->next->next;
25            if(slow == fast){
26                break;
27            }
28        }
29
30        if(fast == nullptr || fast->next == nullptr){
31            return nullptr; //no cycle
32        }
33
34        ListNode* p1 = slow;
35        ListNode* p2 = head;
36
37        while(p1!=p2){
38            p1 = p1->next;
39            p2 = p2->next;
40        }
41
42        return p1;
43
44    }
45};