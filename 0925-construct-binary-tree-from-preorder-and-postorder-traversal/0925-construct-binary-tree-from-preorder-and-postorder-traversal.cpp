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
unordered_map<int,int>mp1;
  unordered_map<int,int>mp;
TreeNode*solve(vector<int>&pre,vector<int>&pos,int ind,int start,int last){
    if(start>last){
        return NULL;
    }
    TreeNode* root=new TreeNode(pre[ind]);
    if(start==last){
        return root;
    }
  int lroot=pre[ind+1];
  int lrind=mp1[lroot];
    root->left=solve(pre,pos,ind+1,start,lrind);
    root->right=solve(pre,pos,mp[pos[last-1]],lrind+1,last-1);
    return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
      
        for(int i=0;i<preorder.size();i++){
            mp[preorder[i]]=i;
            mp1[postorder[i]]=i;
        }
        TreeNode* ans=solve(preorder,postorder,0,0,postorder.size()-1);
        return ans;
    }
};