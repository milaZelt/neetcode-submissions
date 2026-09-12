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
    void inorder(TreeNode* root, vector <int>& answer){
        if(root==nullptr) return;
        inorder(root->left, answer);
        answer.push_back(root->val);
        inorder(root->right, answer);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector <int> answer;
        inorder(root, answer);

        return answer[k-1];
    }
};
