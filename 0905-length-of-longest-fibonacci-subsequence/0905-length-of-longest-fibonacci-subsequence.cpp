class Solution {
public:

    int lenLongestFibSubseq(vector<int>& arr) {
      //  memset(dp,-1,sizeof(dp));
     int n=arr.size();
     int ans=0;
     vector<vector<int>>dp(n,vector<int>(n,0));
     for(int i=2;i<arr.size();i++){
        int start=0;
        int last=i-1;
        while(start<last){
            int sum=arr[start]+arr[last];
            if(sum==arr[i]){
                dp[last][i]=dp[start][last]+1;
                ans=max(ans,dp[last][i]);
                last--;
                start++;
            }
            else if(sum>arr[i]){
                last--;
            }
            else{
                start++;
            }
        }
     }
     if(ans==0){
        return ans;
     }
     return ans+2;
    }
};