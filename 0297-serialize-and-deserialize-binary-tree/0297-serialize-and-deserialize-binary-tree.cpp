/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*>q;
        if(root)
            q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL) {
                ans += "n,";
                continue;
            }
            ans += to_string(front->val) + ",";
            q.push(front->left);
            q.push(front->right);
        }
        if(!ans.empty() && ans.back() == ',') ans.pop_back();
        return ans;
    }

    TreeNode* createTree(vector<int>&nums){
        if(nums.empty()) return NULL;
        int idx = 0;
        int n = nums.size();
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(nums[idx]);
        q.push(root);
        while(idx < n && !q.empty()){
            TreeNode* front = q.front();
            q.pop();
            idx++;
            if(idx < n){
                if(nums[idx] == 1e9){
                    front->left = NULL;
                }else{
                    TreeNode* newNode = new TreeNode(nums[idx]);
                    front->left = newNode;
                    q.push(newNode);
                }
            }
            idx++;
            if(idx < n){
                if(nums[idx] == 1e9){
                    front->right = NULL;
                }else{
                    TreeNode* newNode = new TreeNode(nums[idx]);
                    front->right = newNode;
                    q.push(newNode);
                }
            }
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        stringstream ss(s);
        string d;
        vector<int>nums;
        while(getline(ss, d, ',')){
            if(d == "n"){
                nums.push_back(1e9);
            }else nums.push_back(stoi(d));
        }
        // for(auto i: nums) cout << i << " ";
        TreeNode* root = createTree(nums);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));