1class Solution {
2public:
3    Node* flatten(Node* head) {
4        if (!head) return nullptr;
5
6        Node* dummy = new Node(0);  // Dummy node to simplify pointer manipulation
7        Node* prev = dummy;
8
9        flattenDFS(head, prev);
10
11        // Detach the dummy node
12        dummy->next->prev = nullptr;
13        return dummy->next;
14    }
15
16private:
17    void flattenDFS(Node* curr, Node*& prev) {
18        if (!curr) return;
19
20        prev->next = curr;
21        curr->prev = prev;
22
23        prev = curr;  // Update prev to the current node
24
25        Node* nextNode = curr->next;  // Store next node because it may get overwritten
26
27        if (curr->child) {
28            flattenDFS(curr->child, prev);
29            curr->child = nullptr;  // Clear the child pointer
30        }
31
32        flattenDFS(nextNode, prev);
33    }
34};
35