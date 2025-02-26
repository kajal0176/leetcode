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
    bool check(TreeNode* root,long min,long mx,bool &f){
       
         if((root->val<=min)||(root->val>=mx)){
            f= false;
             return false;
        }
        if(root->left){
            if(!check(root->left,min,root->val,f)){
              return false;
            }
        }
        if(root->right){
             if(!check(root->right,root->val,mx,f)) return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        bool f=true;
        long max=LONG_MAX;
        long mn=LONG_MIN;
     return check(root,mn,max,f);
      //  return f;
      
    }
};