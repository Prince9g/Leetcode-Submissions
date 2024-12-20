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
    void solveUsingDFS(TreeNode*  l, TreeNode*  r, int level){
        if(l == NULL || r==NULL) return;
        if(level & 1) swap(l->val, r->val);
        solveUsingDFS(l->left, r->right, level+1);
        solveUsingDFS(l->right, r->left, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return NULL;
        int level = 0;
        solveUsingDFS(root->left, root->right, 1);
        return root;
    }
};