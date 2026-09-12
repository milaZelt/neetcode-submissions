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
    void dfs(TreeNode* root, vector<int>& answer){
       if(root==nullptr){return;} 
       //go left 
        dfs(root->left,answer);

        //prosses current node
        answer.push_back(root->val);

        //go right
        dfs(root->right,answer);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        dfs(root,answer);
        return answer;
    }
};