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
    void check(TreeNode* root,long min,long mx,bool &f){
       
         if((root->val<=min)||(root->val>=mx)){
            f= false;
             return;
        }
        if(root->left){
            check(root->left,min,root->val,f);
        }
        if(root->right){
             check(root->right,root->val,mx,f);
        }
    }
    bool isValidBST(TreeNode* root) {
        bool f=true;
        long max=LONG_MAX;
        long mn=LONG_MIN;
      check(root,mn,max,f);
        return f;
      
    }
};