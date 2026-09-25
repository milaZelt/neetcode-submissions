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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue <pair<TreeNode*, TreeNode* > > qu;
        qu.push({p, q});

        while(!qu.empty()){
            auto [pNode, qNode] = qu.front();
            qu.pop();

            if(qNode==nullptr&& pNode==nullptr){
                continue;
            }

            if(pNode==nullptr && qNode!=nullptr ){
                return false;
            }
            if(qNode==nullptr && pNode!=nullptr ){
                return false;
            }
            if(pNode->val != qNode->val){
                return false;
            }

            qu.push({pNode->left, qNode->left});
            qu.push({pNode->right, qNode->right});

        }
        return true;
    }
};
