/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //bool flag; 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if( p == q ) return p;
        //if(root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if((left == p && right == q )|| 
        (left == q && right == p ) || 
        (root == p) || (root == q))
            return root;
        else if(left == p || right == p) return p;
        else if(right == q || left == q) return q;
        
        if(left != NULL) return left;
        else if(right != NULL) return right;
        else return NULL;
    }
};
