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
14    Node* flatten(Node* head) {
15        if(!head){
16            return nullptr;
17        }
18        stack<Node*> st;
19        st.push(head);
20        Node* dumh = new Node(-1);
21        Node* cur = dumh;
22        while(!st.empty()){
23            auto tn = st.top(); st.pop();
24            
25            if(tn->next){
26                st.push(tn->next);
27            }
28            if(tn->child){
29                st.push(tn->child);
30            }
31            cur->next = tn;
32            tn->prev = cur;
33            cur = cur->next;
34            cur->child = nullptr;
35        }
36
37        head->prev = nullptr;
38
39        return head;
40
41    }
42};