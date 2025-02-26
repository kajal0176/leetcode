class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
      int sum=0;
      int mx=INT_MIN;
       int mn=INT_MAX;
       int mnsum=0;
      for(int i=0;i<nums.size();i++){
       
       sum=max(sum+nums[i],nums[i]);
       mx=max(mx,sum);
       mnsum=min(mnsum+nums[i],nums[i]);
       mn=min(mnsum,mn);
      }
     
       return max(abs(mn),abs(mx));
    }
};