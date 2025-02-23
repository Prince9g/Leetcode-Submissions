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
    TreeNode* solve(int preS, int preE, int postS, vector<int>&preOrder, vector<int>&postOrder){
        if(preS > preE) return NULL;
        // if(postS >= postOrder.size()) return NULL;
        TreeNode* root = new TreeNode(preOrder[preS]);
        if(preS == preE) return root;
        int newNode = preOrder[preS+1];
        int j=postS;
        while(postOrder[j] != newNode){
            j++;
        }
        int size = j-postS+1;
        root->left = solve(preS+1, preS+size, postS, preOrder, postOrder);
        root->right = solve(preS+size+1, preE, j+1, preOrder, postOrder);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(0,preorder.size()-1,0,preorder, postorder);
    }
};