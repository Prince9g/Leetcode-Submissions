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
    int search(vector<int>&inorder, int target){
        int n = inorder.size();
        for(int i=0; i<n; i++){
            if(target == inorder[i]) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder, int s, int e, int &p){
        if(s > e) return NULL;
        if(preorder.size() <= p) return NULL;
        int key = search(inorder, preorder[p]);
        TreeNode* root = new TreeNode(inorder[key]);
        p++;
        root->left = solve(preorder, inorder, s, key-1, p);
        root->right = solve(preorder, inorder, key+1, e, p);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        int p = 0;
        return solve(preorder, inorder, 0, inorder.size()-1, p);
    }
};