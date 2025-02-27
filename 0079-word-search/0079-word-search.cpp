class Solution {
public:
bool solve(vector<vector<char>>&board,int i,int j,int ind,string word,vector<vector<int>>&vis){
   if(ind==word.size()){
    return true;
   }
   //cout<<i<<" "<<j<<"\n";
   if(i>=board.size()||j>=board[i].size()||vis[i][j]==1){
    return false;
   }
    bool ans=false;
    vis[i][j]=1;
  if(word[ind]==board[i][j]){
  ans=ans|solve(board,i+1,j,ind+1,word,vis);
  ans=ans|solve(board,i-1,j,ind+1,word,vis);
  ans=ans|solve(board,i,j+1,ind+1,word,vis);
  ans=ans|solve(board,i,j-1,ind+1,word,vis);
  }
  vis[i][j]=0;
  //cout<<ans<<" ";
  return ans;
}
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[i].size();j++){
             if(solve(board,i,j,0,word,vis)){
                return true;
             }
            }
        }
         return false;
    }
};