1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* prev;
7    Node* next;
8    Node* child;
9};
10*/
11
12class Solution {
13public:
14    Node* dumh;
15    Node* cur;
16    unordered_map<Node*, int> ump;
17    void rec(Node* head){
18        if(head == nullptr) return;
19
20        // Node* newn = new Node(head->val);
21        cur->next = head;
22        head->prev = cur;
23
24        cur = cur->next;
25        
26        queue<Node*> q;
27        if(head->child){
28            q.push(head->child);
29        }
30        if(head->next){
31            q.push(head->next);
32        }
33        cur->next = nullptr;
34        cur->child = nullptr;
35        while(!q.empty()){
36            auto tn = q.front(); q.pop();
37            rec(tn);
38        }
39    }
40
41    Node* flatten(Node* head) {
42        dumh = new Node(-1);
43        cur = dumh;
44        rec(head);
45        if(head){
46            head->prev = nullptr;
47        }
48        return head;
49    }
50};