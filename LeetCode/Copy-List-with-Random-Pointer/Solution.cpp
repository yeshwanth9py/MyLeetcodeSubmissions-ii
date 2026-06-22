1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* next;
7    Node* random;
8    
9    Node(int _val) {
10        val = _val;
11        next = NULL;
12        random = NULL;
13    }
14};
15*/
16
17class Solution {
18public:
19    Node* copyRandomList(Node* head) {
20        if(!head) return nullptr;
21        Node* cur = head;
22        while(cur){
23            Node* fut = cur->next;
24            Node* newnd = new Node(cur->val);
25            newnd->next = fut;
26            cur->next = newnd;
27            cur = fut;
28        }
29
30        cur = head;
31        Node* nhead = cur->next;
32        while(cur){
33            Node* ra = cur->random;
34            Node* dup = cur->next;
35            dup->random = (ra?ra->next:nullptr);
36            cur = cur->next->next;
37        }
38
39        cur = head;
40        while(cur){
41            Node* dup = cur->next;
42            Node* nex = cur->next->next;
43            dup->next = (nex?nex->next:nullptr);
44            cur->next = nex;
45            cur = cur->next;
46        }
47
48        return nhead;
49    }
50};