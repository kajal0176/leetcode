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
     TreeNode* ans;
    TreeNode* help(TreeNode* root, TreeNode* p, TreeNode* q){
         if(root==NULL){
            // ans=NULL;
            return NULL ;
        }
        // if((p->val>=root->val&&q->val<=root->val)||(p->val<=root->val&&q->val>=root->val)){
        //    ans=root;
        //     return root ;
        // }
        if(p->val<root->val&&q->val<root->val){
           return help(root->left,p,q);
        }
        if(p->val>root->val&&q->val>root->val){
           return help(root->right,p,q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      return help(root,p,q);
       // return ans;
       // return root;
    }
};