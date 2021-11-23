/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example 2:

Input: root = []
Output: []
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* connect(Node* root) {
        Node* temp = root;
       if(root == NULL) {
            return NULL;
        }
        while(root->left) {
		// Need to create a temp variable here otherwise   when doing this root = root -> left; it will go null everytime
            Node *p = root;
            while(p != NULL) {
                p->left->next = p->right;
                if(p->next != NULL) {
                    p->right -> next = p->next->left;
                }
                p = p->next;
            }
            root = root -> left;
        }
        return temp;

    }
};
