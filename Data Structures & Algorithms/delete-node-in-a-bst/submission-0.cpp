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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //first look for value
        if(root==nullptr){
            return nullptr;
        }
        if(root->val > key){
            root->left=deleteNode(root->left, key);
        }else if(root->val < key){
            root->right = deleteNode( root->right, key);
        }else{
            //its the node we want to delete, we have 3 cases

            //(case 1): has no childern 
            if(root->right==nullptr && root->left==nullptr){
                return nullptr;
            }

            //(case 2): has one child
            if (root->left==nullptr){
                return root->right;
            }
            if(root->right==nullptr){
                return root->left;
            }

            //(case 3): has two childern
            TreeNode* smallestRight=root->right;
            while(smallestRight->left !=nullptr){
                smallestRight=smallestRight->left;
            }
            //rpleace val with SmallestRight
            root->val=smallestRight->val;

            //delete old value
            root->right= deleteNode(root->right, smallestRight->val);
    
        }
        return root;
        
    }
};