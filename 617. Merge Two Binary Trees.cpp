/*
You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Example 2:

Input: root1 = [1], root2 = [1,2]
Output: [2,2]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(r1==NULL) return r2;
        if(r2==NULL) return r1;

        TreeNode *t= new TreeNode(0);
        if(r1!=NULL && r2!=NULL)
            t->val=r1->val+r2->val;

        t->left=mergeTrees(r1->left,r2->left);
        t->right=mergeTrees(r1->right,r2->right);
        return t;

    }
};
