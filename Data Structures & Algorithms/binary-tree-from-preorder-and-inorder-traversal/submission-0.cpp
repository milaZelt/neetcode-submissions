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
    TreeNode* build(vector <int>& preorder, vector <int>& inorder, int& preIndex, int left, int right){
        if (left>right){
            return nullptr;
        }

        //find what root form pre order
        int rootVal= preorder[preIndex];
        preIndex++;

        TreeNode* root= new TreeNode(rootVal);

        //find the root loction
        int mid;
        for(int i=left; i<= right; i++ ){
            if(inorder[i]==rootVal){
                mid=i;
                break;
            }
        }

        root->left= build(preorder, inorder, preIndex, left, mid-1);
        root->right= build(preorder, inorder, preIndex, mid+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        return build(preorder, inorder, preIndex, 0, inorder.size()-1 );
    }
};
