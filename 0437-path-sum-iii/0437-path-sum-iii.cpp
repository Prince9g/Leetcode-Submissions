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
    void solve(TreeNode* root, int targetSum, long long sum, int &ans) {
    if (root == NULL) {
        return;
    }

    // Add the current node's value to the sum
    sum += root->val;

    // Check if the current sum equals the targetSum
    if (sum == targetSum) {
        ans++;
    }

    // Continue to check in the left and right subtrees
    solve(root->left, targetSum, sum, ans);
    solve(root->right, targetSum, sum, ans);
}

void findPaths(TreeNode* root, int targetSum, int &ans) {
    if (root == NULL) {
        return;
    }

    // Solve for the current node as the starting point
    solve(root, targetSum, 0, ans);

    // Recursively try for the left and right subtrees
    findPaths(root->left, targetSum, ans);
    findPaths(root->right, targetSum, ans);
}

int pathSum(TreeNode* root, int targetSum) {
    int ans = 0;
    findPaths(root, targetSum, ans);
    return ans;
}

};