class Solution {
public:
   int solve(vector<vector<int>>&queries,int ind,int i,int target,vector<vector<int>>&dp){
    if(target==0)return ind;
    if(ind>=queries.size()||target<0)return queries.size()+1;
    if(dp[ind][target]!=-1)return dp[ind][target];
    int ntk=solve(queries,ind+1,i,target,dp);
    int tk=1e9;
    if(queries[ind][0]<=i&&queries[ind][1]>=i){
        tk=solve(queries,ind+1,i,target-queries[ind][2],dp);
    }
    return dp[ind][target]=min(tk,ntk);
   }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
      int ans=-1;
      for(int i=0;i<nums.size();i++){
        vector<vector<int>>dp(queries.size()+1,vector<int>(nums[i]+1,-1));
        int t=solve(queries,0,i,nums[i],dp);
        ans=max(ans,t);
      }
      return (ans>queries.size())?-1:ans;
    }
};