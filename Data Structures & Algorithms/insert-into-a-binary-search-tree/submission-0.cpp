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
 #include <bits/stdc++.h>
 using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //if no nodes just add new node
        if (root==nullptr){
            return new TreeNode(val); 
        }

        //if smaller
        if(val<root->val){
            root->left=insertIntoBST(root->left, val);

        }else{// if bigger
            root->right=insertIntoBST(root->right, val);
        }
        return root;
    }
};