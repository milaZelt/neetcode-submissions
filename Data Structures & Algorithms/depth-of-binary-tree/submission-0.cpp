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
    int dfs(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left= dfs(root->left);
        int right=dfs(root->right);
        
        return max(right, left)+1;
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
        
    }
};
