class Solution {
public:

int solve(vector<int>&nums,int mid,int k){
    int cnt=0;
   for(int i=0;i<nums.size();i++){
    if(nums[i]<=mid){
       cnt++;
       i++;
    }

   }
   return cnt>=k;
}
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
       // vector<vector<int>>dp(n,vector<int>(k+1,-1));
       int ans=-1;
       int i=1;
       int j=*max_element(nums.begin(),nums.end());
       while(i<=j){
        int mid=(i+j)/2;
        if(solve(nums,mid,k)){
            ans=mid;
            j=mid-1;
        }
        else{
            i=mid+1;
        }
       }
       return ans;
    }
};