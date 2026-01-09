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
  TreeNode* LCA(TreeNode* root,TreeNode* node1, TreeNode* node2){
    if(!root){
        return NULL;
    }
    if(root->val==node1->val||root->val==node2->val){
        return root;
    }
    TreeNode* left=LCA(root->left,node1,node2);
    TreeNode* right=LCA(root->right,node1,node2);
    if(left && right){
        return root;
    }
    if(!left){
        return right;
    }
    return left;
  }
  int height(TreeNode* root){
    if(!root){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
  }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root){
            return root;
        }
        int ht=height(root);
        queue<TreeNode*>q;
        vector<TreeNode*>v;
        q.push(root);
        int cnt=1;
        while(!q.empty()){
            int n=q.size();
          for(int i=0;i<n;i++){
            auto it=q.front();
            if(cnt==ht){
                v.push_back(it);
            }
            q.pop();
            if(it->left){
                q.push(it->left);
            }
            if(it->right){
                q.push(it->right);
            }
          }
       cnt++;

        }
        if(v.size()==1){
            return v[0];
        }
        TreeNode*ans=LCA(root,v[0],v[1]);
        for(int i=2;i<v.size();i++){
            ans=LCA(root,ans,v[i]);
        }
        return ans;
    }
};