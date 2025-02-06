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
    int checkHeight(TreeNode* root){
        if(root == NULL) return 0;
        return 1+max(checkHeight(root->left), checkHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lHeight = checkHeight(root->left);
        int rHeight = checkHeight(root->right);
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(left && right && abs(lHeight - rHeight) <=1){
            return true;
        }
        return false;
    }
};