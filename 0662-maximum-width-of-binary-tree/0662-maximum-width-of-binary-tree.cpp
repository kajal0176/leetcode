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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int ans=0;
        while(!q.empty()){
           int x=q.size();
            int lh=-1;
            int rh=-1;
            auto t=q.front();
           for(int i=0;i<x;i++){
             auto it=q.front();
            q.pop();
           
           int diff=abs(it.second-t.second);
            if(i==0){
                lh=abs(it.second-t.second);
               
            }
            if(i==x-1){
                 rh=abs(it.second-t.second);
            }
            if(lh!=-1&&rh!=-1){
                ans=max(ans,rh-lh+1);
            }
            if(it.first->left){
                q.push({it.first->left,(diff*1L)*2});
            }
            if(it.first->right){
                q.push({it.first->right,(diff*1L)*2+1});
            }
           
           }
          
           
        }
        return ans;
    }
};