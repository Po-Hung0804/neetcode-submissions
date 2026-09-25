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
    int index=0;
    unordered_map<int,int> mapping;
    TreeNode* find(vector<int>& preorder, int start, int end){
        if(start>end){
            return nullptr;
        }
        int root_val=preorder[index];
        index++;
        TreeNode* root=new TreeNode(root_val);
        int m= mapping[root_val];
        root->left=find(preorder,start,m-1);
        root->right=find(preorder,m+1,end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // first find the root by using preorder the first element in preorder is root 
        // find the root index in inorder then we can find the left tree and right tree 
        // preorder: mid-> left-> right
        // inorder: left-> mid-> right
        // postorder: left-> right-> mid

        int n=preorder.size();
        for(int i=0; i<n; i++){
            mapping[inorder[i]]=i;
        }
        return find(preorder,0,n-1);
    } 
};
