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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // three condition if p<root<q the ancestor is root if p<q<root the ancestor is in root->left if root<p<q the ancestor is in root->right
        if(!root || !p || !q){
            return nullptr;
        }
        if(max(p->val,q->val)<root->val){
            // ancestor in the root->left 
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val< min(p->val,q->val)){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }
    }
};
