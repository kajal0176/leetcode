class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int xr=0;
        int i=0;
        int j=0;
        int ans=1;
        while(j<nums.size()){
            while((xr&nums[j])>0){
                xr=xr^nums[i];
                i++;
            }
             if((xr&nums[j])==0){
                ans=max(ans,j-i+1);
              }
             xr^=nums[j];
                j++;
        }
        return ans;
    }
};