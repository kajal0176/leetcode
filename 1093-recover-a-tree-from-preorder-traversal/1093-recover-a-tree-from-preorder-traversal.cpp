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
TreeNode* solve(string&s,int depth,int& ind){
   if(ind>=s.size()){
    return NULL;
   }
   int d=0;
   while(s[ind]=='-'){
    d++;
    ind++;
   }
   if(depth>d){
    ind-=d;
    return NULL;
   }
   int x=0;
   while(isdigit(s[ind])){
    x=x*10+s[ind]-'0';
    ind++;
   }
 //  cout<<ind<<" ";
   TreeNode* nd=new TreeNode(x);
   nd->left=solve(s,d+1,ind);
   nd->right=solve(s,d+1,ind);
   return nd;
}
    TreeNode* recoverFromPreorder(string s) {
        int ind=0;
       return solve(s,0,ind);
    }
};