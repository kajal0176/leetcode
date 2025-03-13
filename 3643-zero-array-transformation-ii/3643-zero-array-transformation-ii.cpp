class Solution {
public:
bool isp(vector<int>nums,vector<vector<int>>&queries,int mid){
    vector<int>diff(nums.size()+1,0);
    for(int i=0;i<=mid;i++){
        int lft=queries[i][0];
        int rgt=queries[i][1];
        diff[lft]+=queries[i][2];
        diff[rgt+1]-=queries[i][2];
    }
    int count=0;
    for(int i=0;i<nums.size();i++){
      //  cout<<diff[i]<<" ";
      count+=diff[i];
      if(nums[i]>count)return false;
    }
    return true;
}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int i=0;
        int j=queries.size()-1;
        int ans=-1;
        int f=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                f=0;
                break;
            }
        }
        if(f==1)return 0;
        while(i<=j){
            int mid=(i+j)/2;
           
            if(isp(nums,queries,mid)){
                 cout<<mid<<" ";
                ans=mid+1;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};